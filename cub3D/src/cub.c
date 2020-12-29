/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/29 19:29:37 by mochegri         ###   ########.fr       */
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

    i = 0;
    // while(++i < game->cube->nbr_ligne)
    // {
        j = 0;
    //     while (++j < game->cube->nbr_column)
    //     {
            color = 0x00;
            tileX = j * tile_size;
            tileY = i * tile_size;
            color = (game->cube->map[i][j] == '1') ? 0x8b1c62 : 0xff7256;
            // if(game->cube->map[i][j] != ' ')
            // {
                sqr.x = tileX * map_coef;
                sqr.y = tileY *map_coef;
                sqr.lent = tile_size * map_coef;
                draw_rect(&(game->img), sqr, color);
    //         }
    //     }
    // }
}

void	ft_render_player(t_game *game1)
{
    t_point p1;
    t_point p2;
    
    p1.x = game1->player->y;
    p1.y = game1->player->x;
    p2.x = game1->player->y * sin(game1->player->rotationAngle);
    p2.y = game1->player->x * cos(game1->player->rotationAngle);
	ft_draw_disque(&(game1->img), (game1->player->y) * map_coef,
	(game1->player->x) * map_coef, 5, 0xfff68f);
	ft_render_line(&(game1->img), p1,p2, 0xf0f68f);

}