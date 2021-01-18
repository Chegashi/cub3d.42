/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/18 18:34:42 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		ft_draw_map(t_game *game)
{
    int i;
    int j;
    int tileX;
    int tileY;
    int color;
    t_square sqr;

    i = -1;
    while(++i < game->cube->nbr_ligne)
    {
        j = -1;
        while (++j < game->cube->nbr_column)
        {
            color = 0x00;
            tileX = j * tile_size;
            tileY = i * tile_size;
            color = (game->cube->map[i][j] == '1') ? 0x8b1c62 : 0xff7256;
            if(game->cube->map[i][j] != ' ')
            {
                sqr.x = tileX * map_coef;
                sqr.y = tileY * map_coef;
                sqr.lent = tile_size * map_coef;
                draw_rect(&(game->img), sqr, color);
            }
        }
    }
}

int			ft_update(t_player *p , t_game *game)
{
	float move;
    t_player *new_player;
    
    new_player = (t_player *)malloc(sizeof(t_player));
    *new_player = *p;
	move = p->walkDirection * p->walkSpeed;
	new_player->x += cos(p->rotationAngle) * move;
	new_player->y += sin(p->rotationAngle) * move;
    new_player->rotationAngle += p->turnDirection * p->turnSpeed;
    ft_normilised(&(new_player->rotationAngle));
    if(!ft_is_wall(new_player->x, new_player->y, game))
        *p = *new_player;
    free(new_player);
	return 0;
}

int ft_is_wall(float x, float y, t_game *game)
{
    int x_index;
    int y_index;

    x_index = floor(x) / tile_size;
    y_index = floor(y) / tile_size;
    if(x < 0 || y < 0 || x > game->cube->resolution[0] || y > game->cube->resolution[1])
        return (0);
    return(game->cube->map[y_index][x_index] == '1');
}
