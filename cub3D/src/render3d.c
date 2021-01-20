/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:08:20 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/20 10:24:08 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void    ft_render_3d(t_game *game, t_ray *ray)
{
    float   dis_wall_p;
    float   wall_h;
    t_rectangle     rect;
    rect.color = 0xabc12;
    // while (++i < game->cube->resolution[0])
    // {
        dis_wall_p =  (game->cube->resolution[1] / 2) * tan(FOV / 2);
        wall_h = (TILE_SIZE / ray->dist) * dis_wall_p;
        rect.x = ray->clomn_id;
        rect.y = (game->cube->resolution[1] / 2) - wall_h / 2;
        rect.lent_x = 1;
        rect.lent_y = wall_h;
        rect.y *= ( rect.y < 0) ? 0 : 1; 
        //printf("(x:%f y:%f)\t(dx:%f dy:%f)\n", rect.x, rect.y, rect.lent_x, rect.lent_y);
        ft_render_g_rect(&(game->img), rect);
        //printf("%d\n", ray->clomn_id);
    // }
}