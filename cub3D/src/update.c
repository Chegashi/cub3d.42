/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:04:12 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/24 19:29:49 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_update(t_player *p)
{
	double		move;

	move = p->walkdirection * p->walkspeed;
	p->rotationangle += p->turndirection * p->turnspeed;
	if (!p->turndirection)
	{
		p->x += cos(p->rotationangle) * move;
		p->y += sin(p->rotationangle) * move;
	}
	ft_normilised(&(p->rotationangle));
	if (!ft_antoured_bywall(p->x, p->y) && !ft_isasprite(p->x, p->y))
		*(g_game->player) = *p;
	if (g_game->player->z > g_game->hight
	|| g_game->player->z < -1 * g_game->hight)
		g_game->player->z *= -1;
	g_game->plyr.x = g_game->player->x;
	g_game->plyr.y = g_game->player->y;
	free(p);
	ft_render();
	return (0);
}

int				ft_is_wall(double x, double y)
{
	int			x_index;
	int			y_index;

	if (x < 0 || y < 0 || x > g_game->width || y > g_game->width)
		return (0);
	x_index = floor(x) / g_game->ts;
	y_index = floor(y) / g_game->ts;
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
	if (p.x < 0 || p.y < 0
		|| floor(p.x / g_game->ts) > g_game->cube->nbr_column - 1
		|| floor(p.y / g_game->ts) > g_game->cube->nbr_ligne - 1)
		return (0);
	return (1);
}

void			ft_scren_shot(void)
{
	ft_save();
	ft_exit(EXIT_SUCCESS);
}
