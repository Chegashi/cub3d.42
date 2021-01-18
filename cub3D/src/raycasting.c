/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:13:57 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/18 18:34:12 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ft_render_rays(t_game *game)
{
	float angl;
	int clomn_id;
	t_point p;

	p.x = game->player->x;
	p.y = game->player->y;
	clomn_id = -1;
	angl = game->player->rotationAngle - FOV / 2;
	while (clomn_id++ < game->cube->resolution[0])
	{
		ft_normilised(&angl);
		ft_cast_rays(game, angl);
	 	angl += FOV / game->cube->resolution[0];
	}
}

void     ft_horis_interst(t_game *game, t_ray *ray)
{
    ray->h_start_p.y = floor(game->player->y / tile_size) * tile_size;
	ray->h_start_p.y += (ray->is_facing & DOWN) ? tile_size : 0;
	ray->h_start_p.x = game->player->x + (ray->h_start_p.y - game->player->y)
    / tan(ray->angl);
	ray->h_y_steps = tile_size * ((ray->is_facing & UP) ? - 1 : 1);
	ray->h_x_steps = tile_size / tan(ray->angl);
	ray->h_x_steps *= ((ray->is_facing & LEFT) && ray->h_x_steps > 0) ? - 1 : 1;
	ray->h_x_steps *= ((ray->is_facing & RIGHT) && ray->h_x_steps < 0) ? - 1 : 1;
	ray->h_end_p = ray->h_start_p;
	ray->h_end_p.y -= (ray->is_facing & UP) ? 1 : 0;
	while (ft_is_in_map(ray->h_end_p, game))
	{
		if(ft_is_wall(ray->h_end_p.x , ray->h_end_p.y, game))
		{
			ray->is_facing |= HIT_HORIS;
			break;
		}
		else
		{
			ray->h_end_p.x += ray->h_x_steps;
			ray->h_end_p.y += ray->h_y_steps ;
		}
	}
}

void	ft_verti_intersect(t_game *game, t_ray *ray)
{
	ray->v_start_p.x = floor(game->player->x / tile_size) * tile_size;
	ray->v_start_p.x += (ray->is_facing & RIGHT) ? tile_size : 0;
	ray->v_start_p.y = game->player->y + (ray->v_start_p.x - game->player->x) * tan(ray->angl);
	ray->v_x_steps = tile_size * ((ray->is_facing & LEFT) ? - 1 : 1);
	ray->v_y_steps = tile_size * tan(ray->angl);
	ray->v_y_steps *= ((ray->is_facing & UP) && ray->v_y_steps > 0) ? - 1 : 1;
	ray->v_y_steps *= ((ray->is_facing & DOWN) && ray->v_y_steps < 0) ? - 1 : 1;
	ray->v_end_p = ray->v_start_p;
	ray->v_end_p.x -= (ray->is_facing & LEFT) ? 1 : 0;
	//printf("steps:(%0.f, %0.f)\t angl:%0.f \ttang%f\n", ray->v_x_steps, ray->v_y_steps , ray->angl *(180/PI), tan(ray->angl));
	while (ft_is_in_map(ray->v_end_p, game))
	{
		if(ft_is_wall(ray->v_end_p.x , ray->v_end_p.y, game))
		{
			ray->is_facing |= HIT_VERTI;
			break;
		}
		else
		{
			ray->v_end_p.x += ray->v_x_steps;
			ray->v_end_p.y += ray->v_y_steps;
		}
	// 	printf("end:(%.0f,%.0f)\tangle:%f\n", ray->v_end_p.x, ray->v_end_p.y, ray->angl * (180/PI));
	}
}

void	ft_cast_rays(t_game *game, float angl)
{
	t_ray	ray;
	t_point p2;
	t_point	p1;

    ray.angl = angl;
	ft_normilised(&(ray.angl));
	ray.is_facing = 0;
	ray.is_facing |= (angl > 0 && angl < PI) ? DOWN : UP;
	ray.is_facing |= (angl > PI / 2 && angl < (3 * PI) / 2) ? LEFT : RIGHT;
	//printf("angl: %f\n", ray.angl *(180/PI));
    ft_horis_interst(game, &ray);
	ft_verti_intersect(game, &ray);
	// printf("angl : %f\n",angl * (180/PI));
	// //printf("[py:%f, ay:%f] [dy:%f]\n", game->player->y, ray.h_start_p.y, game->player->y - ray.h_start_p.y);
	// //printf("[px:%f, ax:%f][dx:%f]\n", game->player->x, ray.h_start_p.x, game->player->x -  ray.h_start_p.x);
	// //printf("dx=%f\n",game->player->x - ray.h_start_p.x);
	// //printf("%f\n", angl * (180/ PI));
	p1.x = game->player->x;
	p1.y = game->player->y;
	ray.h_dist = (ray.is_facing & HIT_HORIS) ? ft_dis_2point(p1, ray.h_end_p) : INT_MAX;
	ray.v_dist = (ray.is_facing & HIT_VERTI) ? ft_dis_2point(p1, ray.v_end_p) : INT_MAX;
	p2 = (ray.h_dist < ray.v_dist) ? ray.h_end_p : ray.v_end_p; 

	//p2 = ray.h_end_p;
	// float dis1 = sqrt(pow(game->player->x - p2.x, 2) + pow(game->player->y - p2.y, 2));
	// printf("%f", dis1);
	// p2.x = p1.x + cos(angl)*50;
	// p2.y = p1.y + sin(angl)*50 ;
	
	ft_render_line(&(game->img), p1, p2, 0xFFFF00);
}

int     ft_is_in_map(t_point p, t_game *game)
{
    if (p.x < 0 || p.y < 0 || floor(p.x / tile_size) > game->cube->nbr_column - 1
    || floor(p.y / tile_size) > game->cube->nbr_ligne - 1)
        return (0);
    return (1);
}
t_point		ft_must_close(t_point p, t_point p1, t_point p2)
{
	float dis1;
	float dis2;

	dis1 = ft_dis_2point(p, p1);
	dis2 = ft_dis_2point(p, p2);
	return ((dis1 < dis2) ? p1 : p2);
}

float	ft_dis_2point(t_point p1, t_point p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

float	ft_min(float x1, float x2)
{
	return (x1 < x2) ? x1 : x2;
}