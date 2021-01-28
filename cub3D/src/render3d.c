/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:08:20 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/28 14:48:36 by mochegri         ###   ########.fr       */
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
        p1.y += g_game->player->z;
        p2.y += g_game->player->z;
        g_game->rays[i].wall_start = p1.y;
        g_game->rays[i].wall_end = p2.y;
        ft_render_line(&(g_game->img), p1, p2, 0xffaabb); 
    }
}

void    ft_render_celing()
{
    int         i;
    int         color;
    t_point     p1;
    t_point     p2;
    int         *tab;

    i = -1;
    tab = g_game->cube->ceilling_color;
    color = ft_create_trgb(1,tab[0], tab[1], tab[2]);
    while (++i < g_game->cube->resolution[0])
    {
        p1.x = i;
        p1.y = 0;
        p2.x = i;
        p2.y = g_game->rays[i].wall_start;
        ft_render_line(&(g_game->img), p1, p2, color); 
    }
}

void    ft_render_floor()
{
    int         i;
       int         *tab;
    int         color;

    t_point     p1;
    t_point     p2;

    i = -1;
        tab = g_game->cube->floor_color;
    color = ft_create_trgb(1,tab[0], tab[1], tab[2]);
    while (++i < g_game->cube->resolution[0])
    {
        p1.x = i;
        p1.y = g_game->rays[i].wall_end;
        p2.x = i;
        p2.y = g_game->height;
        ft_render_line(&(g_game->img), p1, p2, color); 
    }
}

int		ft_create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}