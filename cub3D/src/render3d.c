/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:08:20 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/19 19:32:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void    ft_render_3d(t_game *game, t_ray *ray)
{
    int     i;
    float   dis_wall_p;
    float   wall_h;

    i = -1;
    while (++i < game->cube->resolution[0])
    {
        dis_wall_p =  (game->cube->resolution[1] / 2) * tan(FOV / 2);
        wall_h = (TILE_SIZE / ray->dist) * dis_wall_p;
        ft_render_g_rect(i * dis_wall_p, )
    }
    
}