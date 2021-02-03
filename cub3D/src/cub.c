/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/01 16:17:05 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void			ft_render_map(void)
{
	int			i;
	int			j;
	int			tilex;
	int			tiley;
	t_square	sqr;

	i = -1;
	while (++i < g_game->cube->nbr_ligne)
	{
		j = -1;
		while (++j < g_game->cube->nbr_column)
		{
			tilex = j * TILE_SIZE * COEF;
			tiley = i * TILE_SIZE * COEF;
			sqr.color = (g_game->cube->map[i][j] == '1') ? 0x8b1c62 : 0xff7256;
			if (g_game->cube->map[i][j] != ' ')
			{
				sqr.x = tilex;
				sqr.y = tiley;
				sqr.lent = TILE_SIZE;
				draw_rect(&(g_game->img), sqr);
			}
		}
	}
}

int				ft_update(t_player *p)
{
	double		move;
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	*new_player = *p;
	move = p->walkdirection * p->walkspeed;
	new_player->x += cos(p->rotationangle) * move;
	new_player->y += sin(p->rotationangle) * move;
	new_player->rotationangle += p->turndirection * p->turnspeed;
	ft_normilised(&(new_player->rotationangle));
	if (!ft_antoured_bywall(new_player->x, new_player->y) && !ft_isasprite(new_player->x, new_player->y))
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

	x_index = floor(x) / TILE_SIZE;
	y_index = floor(y) / TILE_SIZE;
	if (x < 0 || y < 0 || x > g_game->cube->resolution[0]
			|| y > g_game->cube->resolution[1])
		return (0);
	return (g_game->cube->map[y_index][x_index] == '1');
}

int				ft_isasprite(double x, double y)
{
	int			x_index;
	int			y_index;

	x_index = floor(x) / TILE_SIZE;
	y_index = floor(y) / TILE_SIZE;
	if (x < 0 || y < 0 || x > g_game->cube->resolution[0]
			|| y > g_game->cube->resolution[1])
		return (0);
	return (g_game->cube->map[y_index][x_index] == '2');
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
	if (p.x < 0 || p.y < 0 || floor(p.x / TILE_SIZE) > g_game->cube->nbr_column
	- 1 || floor(p.y / TILE_SIZE) > g_game->cube->nbr_ligne - 1)
		return (0);
	return (1);
}

void	ft_render_rays(void)
{
	int		i;
	t_point	p1;
	t_point p2;

	i = -1;
	while (++i < g_game->width)
	{
		p1.x = g_game->plyr.x * COEF;
		p1.y = g_game->plyr.y * COEF;
		p2.x = (g_game->rays[i].end.x) * COEF;
		p2.y = g_game->rays[i].end.y * COEF;
		ft_render_line(&(g_game->img), p1, p2, 0xff1245);
	}
}