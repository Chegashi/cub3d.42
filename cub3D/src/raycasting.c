/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:13:57 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/30 09:24:57 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void			ft_raycasting()
{
	int			clomn_id;

	clomn_id = -1;
	g_game->rays[0].angl = g_game->player->rotationangle - FOV / 2;
	while (++clomn_id < g_game->width)
	{
		ft_normilised(&(g_game->rays[clomn_id].angl));
		ft_cast_ray(&(g_game->rays[clomn_id]));
		g_game->rays[clomn_id + 1].angl = g_game->rays[clomn_id].angl
		+ FOV / g_game->width;
	}
}

t_point			ft_horis_interst(t_ray *ray)
{
	t_point		a;
	double		x_step;
	double		y_step;

	a.y = floor(g_game->player->y / TILE_SIZE) * TILE_SIZE;
	a.y += (ray->is_facing & DOWN) ? TILE_SIZE : 0;
	a.x = g_game->player->x + (a.y - g_game->player->y) / tan(ray->angl);
	y_step = TILE_SIZE * ((ray->is_facing & UP) ? -1 : 1);
	x_step = TILE_SIZE / tan(ray->angl);
	x_step *= ((ray->is_facing & LEFT) && x_step > 0) ? -1 : 1;
	x_step *= ((ray->is_facing & RIGHT) && x_step < 0) ? -1 : 1;
	a.y -= (ray->is_facing & UP) ? 1 : 0;
	while (ft_is_in_map(a))
		if (ft_is_wall(a.x, a.y))
		{
			ray->is_facing |= HIT_HORIS;
			break ;
		}
		else
			a = ft_translate_point(a, x_step, y_step);
	a.y += (ray->is_facing & UP) ? 1 : 0;
	return(a);
}

t_point			ft_verti_intersect(t_ray *ray)
{
	t_point		a;
	double		x_step;
	double		y_step;

	a.x = floor(g_game->player->x / TILE_SIZE) * TILE_SIZE;
	a.x += (ray->is_facing & RIGHT) ? TILE_SIZE : 0;
	a.y = g_game->player->y + (a.x - g_game->player->x) * tan(ray->angl);
	x_step = TILE_SIZE * ((ray->is_facing & LEFT) ? -1 : 1);
	y_step = TILE_SIZE * tan(ray->angl);
	y_step *= ((ray->is_facing & UP) && y_step > 0) ? -1 : 1;
	y_step *= ((ray->is_facing & DOWN) && y_step < 0) ? -1 : 1;
	a.x -= (ray->is_facing & LEFT) ? 1 : 0;
	while (ft_is_in_map(a))
		if (ft_is_wall(a.x, a.y))
		{
			ray->is_facing |= HIT_VERTI;
			break ;
		}
		else
			a = ft_translate_point(a, x_step, y_step);
	a.x += (ray->is_facing & LEFT) ? 1 : 0;
	return (a);
}

void			ft_cast_ray(t_ray *ray)
{
	t_point		h_pnt;
	t_point		v_pnt;
	double		h_dist;
	double		v_dist;
	static int i =0;
	ray->is_facing = 0;
	ray->is_facing |= (ray->angl > 0 && ray->angl < PI) ? DOWN : UP;
	ray->is_facing |= (ray->angl > PI / 2 && ray->angl < (3 * PI) / 2)
	? LEFT : RIGHT;
	h_pnt = ft_horis_interst(ray);
	v_pnt = ft_verti_intersect(ray);
	h_dist = (ray->is_facing & HIT_HORIS) ?
	ft_dis_2point(g_game->plyr, h_pnt) : INT_MAX;
	v_dist = (ray->is_facing & HIT_VERTI) ?
	ft_dis_2point(g_game->plyr, v_pnt) : INT_MAX;
	ray->end = (h_dist < v_dist) ? h_pnt : v_pnt;
	ray->dist = (h_dist < v_dist) ? h_dist : v_dist;
	//printf("%d\t%f\n",i++,ray->dist);
}
