/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:04:12 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/19 16:18:39 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_update(t_player *p)
{
	double		move;
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	*new_player = *p;
	move = p->walkdirection * p->walkspeed;
	new_player->rotationangle += p->turndirection * p->turnspeed;
	new_player->x += cos(p->rotationangle) * move;
	new_player->y += sin(p->rotationangle) * move;
	ft_normilised(&(new_player->rotationangle));
	if (!ft_antoured_bywall(new_player->x, new_player->y)
		&& !ft_isasprite(new_player->x, new_player->y))
	{
		*p = *new_player;
		g_game->plyr.x = new_player->x;
		g_game->plyr.y = new_player->y;
	}
	if (g_game->player->z > g_game->height
	|| g_game->player->z < -1 * g_game->height)
		g_game->player->z *= -1;
	free(new_player);
	return (0);
}

int				ft_is_wall(double x, double y)
{
	int			x_index;
	int			y_index;

	x_index = floor(x) / g_game->ts;
	y_index = floor(y) / g_game->ts;
	if (x < 0 || y < 0 || x > g_game->cube->resolution[0]
			|| y > g_game->cube->resolution[1])
		return (0);
	return (ft_isin("1 ", g_game->cube->map[y_index][x_index]));
}

int				ft_antoured_bywall(double x, double y)
{
	if (ft_is_wall(x, y) || ft_is_wall(x - 1, y - 1) ||
			ft_is_wall(x - 1, y) || ft_is_wall(x, y - 1) ||
			ft_is_wall(x + 1, y) || ft_is_wall(x, y + 1) ||
			ft_is_wall(x + 1, y + 1))
		return (1);
	return (0);
}

int				ft_is_in_map(t_point p)
{
	if (p.x < 0 || p.y < 0 || floor(p.x / g_game->ts) > g_game->cube->nbr_column
	- 1 || floor(p.y / g_game->ts) > g_game->cube->nbr_ligne - 1)
		return (0);
	return (1);
}

void			ft_scren_shot(void)
{
	ft_save();
	ft_exit(EXIT_SUCCESS);
}
