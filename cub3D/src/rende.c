/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rende.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:00:47 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/15 19:54:13 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void    ft_draw_disque(t_data *data, int x, int y, int r, int color)
{
	int i;
	int j;

	i = x - r;
	while (++i < x + r)
	{
		j = y - r;
		while (++j < y + r)
		{
			if (pow(i - x, 2) + pow(j - y, 2) < pow(r, 2))
				my_mlx_pixel_put(data,i,j,color);
		}
	}
}

void	ft_render_line(t_data *data, t_point p1, t_point p2, int color)
{
	int		k;
	float	xinc;
	float	yinc;
	float	steps;

	steps = (fabs(p1.x - p2.x) > fabs(p1.y - p2.y)) ? fabs(p1.x - p2.x) : fabs(p1.y - p2.y);
	xinc = (p2.x - p1.x) / (float)steps;
	yinc = (p2.y - p1.y) / (float)steps;
	k = -1;
	while (++k < steps)
	{
		my_mlx_pixel_put(data, p1.x * map_coef, p1.y * map_coef, color);
		p1.x += xinc;
		p1.y += yinc; 
	}
}

void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_draw_map(game);
    ft_render_rays(game);
	ft_render_player(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}

void    draw_rect(t_data *data, t_square s, int color)                                                                                                                                
{
	int i;
	int j;
    
    i = s.x -1;
    while (++i < s.x + s.lent)
    {
        j = s.y - 1;
        while (++j < s.y + s.lent)
            my_mlx_pixel_put(data,i,j, (i == s.x || j == s.y) ? 0x00 : color);
    }
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	ft_render_rays(t_game *game)
{
	float angl;
	int clomn_id;
	t_point p;
	//t_point p2;

	p.x = game->player->x;
	p.y = game->player->y;
	clomn_id = -1;
	angl = game->player->rotationAngle - FOV / 2;
	// while (clomn_id++ < game->cube->resolution[0])
	// {
		ft_normilised(&angl);
		ft_cast_rays(game, angl);
	 	angl += FOV / game->cube->resolution[0];
	// }
}
// tn w = dy/dx => dx = dy/tn => xa- xp = dy/tn => xa = xp + (py - ay)tanw
void	ft_cast_rays(t_game *game, float angl)
{
	t_ray	ray;
	//int i =0;
	ft_normilised(&angl);
	ray.is_facing = 0;
	ray.is_facing |= (angl > 0 && angl < PI) ? DOWN : UP;
	ray.is_facing |= (angl > PI / 2 && angl < (3 * PI) / 2) ? LEFT : RIGHT;
	ray.h_start_p.y = floor(game->player->y / tile_size) * tile_size;
	ray.h_start_p.y += (ray.is_facing & DOWN) ? tile_size : 0;
	ray.h_start_p.x = game->player->x + (ray.h_start_p.y - game->player->y) / tan(angl);
	ray.h_x_steps = tile_size / tan(fmod(angl , PI / 4));
	ray.h_x_steps *= ((ray.is_facing & LEFT) && ray.h_x_steps > 0) ? - 1 : 1;
	ray.h_x_steps *= ((ray.is_facing & RIGHT) && ray.h_x_steps < 0) ? - 1 : 1;
	ray.h_y_steps = tile_size * (ray.is_facing & UP) ? - 1 : 1; 
	ray.h_end_p = ray.h_start_p;
	ray.h_end_p.y -= (ray.is_facing & UP) ? 1 : 0;
	while (ft_is_wall(ray.h_end_p.x , ray.h_end_p.y, game))
	{
	
		ray.h_end_p.x += ray.h_x_steps;
		ray.h_end_p.y += ray.h_y_steps;
		// if (++i > 50)
		// break;
	}
	printf("h:[%f, %f]\n", ray.h_end_p.x,ray.h_end_p.y);
	if(ray.h_end_p.x <0)
		ray.h_end_p.x = 0;
	if(ray.h_end_p.x > game->cube->resolution[0])
		ray.h_end_p.x = game->cube->resolution[0];
	// ray.v_start_p.x = floor(game->player->x / tile_size) * tile_size;
	// ray.v_start_p.x += (ray.is_facing & RIGHT) ? tile_size : 0;
	// ray.v_start_p.y = game->player->y + (ray.v_start_p.y - game->player->y) * tan(angl);
	// ray.y_steps = tile_size * tan(angl);
	// ray.v_end_p = ray.v_start_p;
	// while (game->cube->map[(int)(ray.v_end_p.y / tile_size)][(int)(ray.v_end_p.x / tile_size) ] != '1')
	// {
	// 	printf("v[%d, %d]\t %d\n", (int)(ray.v_end_p.y / tile_size), (int)(ray.v_end_p.x / tile_size) , i++);
	// 	ray.v_end_p.x += tile_size;
	// 	ray.v_end_p.y += ray.y_steps;
	// }
	// //printf("[py:%f, ay:%f] [dy:%f]\n", game->player->y, ray.h_start_p.y, game->player->y - ray.h_start_p.y);
	// //printf("[px:%f, ax:%f][dx:%f]\n", game->player->x, ray.h_start_p.x, game->player->x -  ray.h_start_p.x);
	// //printf("dx=%f\n",game->player->x - ray.h_start_p.x);
	// //printf("%f\n", angl * (180/ PI));
	t_point p2, p1;
	p2 = ft_must_close(game, ray.h_end_p, ray.v_end_p);
	p1.x = game->player->x;
	p1.y = game->player->y;
	// p2.x = p1.x + cos(angl)*50;
	// p2.y = p1.y + sin(angl)*50 ;
	
	ft_render_line(&(game->img), p1, p2, 0xFFFF00);
}

void	ft_normilised(float *angle)
{
	if(*angle < 0)
	*angle += 2 * PI;
	*angle = (float)fmod(*angle, 2 * PI);
}

t_point		ft_must_close(t_game *game, t_point p1, t_point p2)
{
	float dis1;
	float dis2;

	dis1 = sqrt(pow(game->player->x - p1.x, 2) + pow(game->player->y - p1.y, 2));
	dis2 = sqrt(pow(game->player->x - p2.x, 2) + pow(game->player->y - p2.y, 2));
	return ( (dis1 < dis2) ? p1 : p2);
}