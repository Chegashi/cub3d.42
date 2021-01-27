/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:08:20 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/27 19:31:47 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void    ft_render_wall()
{
    float       dis_wall_p;
    float       wall_h;
    float       corect_dist;
    int         i;
    t_point     p1;
    t_point     p2;

    i = -1;
    while (++i < g_game->cube->resolution[0])
    {
        corect_dist = g_game->rays[i].dist * cos(g_game->rays[i].angl - g_game->player->rotationangle);
        dis_wall_p =  (g_game->cube->resolution[1] / 2) * tan(FOV / 2);
        wall_h = (TILE_SIZE / corect_dist) * dis_wall_p;
        p1.x = i;
        p1.y = ((g_game->cube->resolution[1] / 2) - wall_h / 2);
        p1.y *= (p1.y < 0) ? 0 : 1;
        p2.x = i;
        p2.y = p1.y + wall_h;
        ft_render_line(&(g_game->img), p1, p2, 0xffaabb);
    }
}