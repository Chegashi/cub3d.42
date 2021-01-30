/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:08:20 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/30 11:34:25 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

#define PV(x, y) printf("%s = " y, #x, x)

void    ft_render_wall()
{
    double       dis_wall_p;
    double       wall_h;
    double       corect_dist;
    int         i;
    t_point     p1;
    t_point     p2;
    int x,y,bp,s_l,en,j;
    double x_off;
    double y_off;
    double dst_top;
    i = -1;   
    double y_step;    
    void *t = mlx_xpm_file_to_image(g_game->mlx_ptr, g_game->cube->north_texture, &x, &y);
    int *tab = (int*)mlx_get_data_addr(t, &bp, &s_l, &en);
    
    //printf("x:%d\ty:%d\tbp:%d\ts_l:%d\ten:%d\t%c\n",x,y,bp,s_l,en,tab[1]);
    //printf("%s\n", g_game->cube->north_texture);
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
        j = p1.y -1;
        // x_off = (g_game->rays[i].is_facing & HIT_VERTI) ? fmod(g_game->rays[i].end.y,TILE_SIZE)
        // : fmod(g_game->rays[i].end.x,TILE_SIZE);
        //x_off = (g_game->rays[i].is_facing & HIT_VERTI) ? (int)g_game->rays[i].end.x % TILE_SIZE : (int)g_game->rays[i].end.y;
        // x_off = (g_game->rays[i].is_facing & HIT_HORIS) ? fmod(g_game->rays[i].end.x, TILE_SIZE) : fmod(g_game->rays[i].end.y,TILE_SIZE);
        if (fmod(g_game->rays[i].end.x, TILE_SIZE) == 0)
            x_off = g_game->rays[i].end.y;
        else
            x_off = g_game->rays[i].end.x;
        x_off = fmod(x_off, TILE_SIZE);
        y_step = y / (p2.y - p1.y);
        x_off = (x_off /TILE_SIZE) * x;
      
        //printf("%d %d\n", x, y);
    //    printf("x:%d\n", (int)x_off);
    //    PV(fmod(g_game->rays[i].end.x, TILE_SIZE), "%lf, ");
    //    PV(fmod(g_game->rays[i].end.y, TILE_SIZE), "%lf\n");
        //printf("")
       // printf("\nx:%d", (int)x_off);
        while(++j < p2.y)
        { 
             double dist_from_top =  j +  wall_h/2 - g_game->width/2;
        //     // dst_top = j + (int)wall_h/2 - g_game->height/2;
            y_off = (dist_from_top  * y) / wall_h;
              //printf("y:%d ", (int)y_off);
            if (x_off < 0 || x_off > x || y_off < 0 || y_off > y)
            1;
            else
            my_mlx_pixel_put(&(g_game->img), i, j, tab[(y * (int)y_off) + (int)x_off]);

        //     // // y_off *= -1;
        //     // if (y_off > y  )
        //     // printf("%f \n", x_off);
        //     //if(g_game->rays[i].angl <= rad_to_deg(0.5) + g_game->player->rotationangle && g_game->rays[i].angl >= -rad_to_deg(0.5) + g_game->player->rotationangle)
        //     y_off += y_step;
        //     //printf("%d\n");
        }
       // printf("\n");
        // ft_render_line(&(g_game->img), p1, p2, 0xffaabb);
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