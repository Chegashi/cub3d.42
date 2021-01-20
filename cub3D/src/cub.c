/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/20 19:33:04 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void			ft_draw_map(t_game *game)
{
	int			i;
	int			j;
	int			tilex;
	int			tiley;
	t_square	sqr;

	i = -1;
	while (++i < game->cube->nbr_ligne)
	{
		j = -1;
		while (++j < game->cube->nbr_column)
		{
			tilex = j * TILE_SIZE * COEF;
			tiley = i * TILE_SIZE * COEF;
			sqr.color = (game->cube->map[i][j] == '1') ? 0x8b1c62 : 0xff7256;
			if (game->cube->map[i][j] != ' ')
			{
				sqr.x = tilex;
				sqr.y = tiley;
				sqr.lent = TILE_SIZE;
				draw_rect(&(game->img), sqr);
			}
		}
	}
}

int				ft_update(t_player *p, t_game *game)
{
	float		move;
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	*new_player = *p;
	move = p->walkdirection * p->walkspeed;
	new_player->x += cos(p->rotationangle) * move;
	new_player->y += sin(p->rotationangle) * move;
	new_player->rotationangle += p->turndirection * p->turnspeed;
	ft_normilised(&(new_player->rotationangle));
	if (!ft_antoured_bywall(new_player->x, new_player->y, game))
		*p = *new_player;
	free(new_player);
	return (0);
}

int				ft_is_wall(float x, float y, t_game *game)
{
	int			x_index;
	int			y_index;

	x_index = floor(x) / TILE_SIZE;
	y_index = floor(y) / TILE_SIZE;
	if (x < 0 || y < 0 || x > game->cube->resolution[0]
			|| y > game->cube->resolution[1])
		return (0);
	return (game->cube->map[y_index][x_index] != '0');
}

int				ft_antoured_bywall(float x, float y, t_game *game)
{
	if (ft_is_wall(x, y, game) || ft_is_wall(x - 1, y - 1, game) ||
			ft_is_wall(x - 1, y, game) || ft_is_wall(x, y - 1, game) ||
			ft_is_wall(x + 1, y, game) || ft_is_wall(x, y + 1, game) ||
			ft_is_wall(x + 1, y + 1, game))
		return (1);
	return (0);
}
