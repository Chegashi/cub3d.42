/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:13:57 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/20 15:39:36 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void			ft_raycasting(void)
{
	int			clomn_id;

	clomn_id = -1;
	g_game->rays[0].angl = g_game->player->rotationangle - FOV / 2;
	g_game->dis_plan = (g_game->width / 2) * tan(FOV / 2);
	while (++clomn_id < g_game->width)
	{
		ft_normilised(&(g_game->rays[clomn_id].angl));
		ft_cast_ray(&(g_game->rays[clomn_id]));
		g_game->rays[clomn_id + 1].angl = g_game->rays[clomn_id].angl
		+ FOV / g_game->width;
		ft_3dgenerate(&(g_game->rays[clomn_id]));
	}
}

void			ft_3dgenerate(t_ray *ray)
{
	double	corect_dis;

	corect_dis = ray->dist * cos(ray->angl - g_game->player->rotationangle);
	ray->wall_h = (g_game->ts / corect_dis) * g_game->dis_plan;
	ray->wall_h *= 3;
	ray->top_pixl = g_game->hight / 2 - ray->wall_h / 2 + g_game->player->z;
	ray->top_pixl *= (ray->top_pixl < 0) ? 0 : 1;
	ray->bottom_pixl = g_game->hight / 2 + ray->wall_h / 2 + g_game->player->z;
	ray->bottom_pixl = (ray->bottom_pixl > g_game->hight) ? g_game->hight
	: ray->bottom_pixl;
}

t_point			ft_horis_interst(t_ray *ray)
{
	t_point		a;
	double		x_step;
	double		y_step;

	a.y = floor(g_game->player->y / g_game->ts) * g_game->ts;
	a.y += (ray->is_facing & DOWN) ? g_game->ts : 0;
	a.x = g_game->player->x + (a.y - g_game->player->y) / tan(ray->angl);
	y_step = g_game->ts * ((ray->is_facing & UP) ? -1 : 1);
	x_step = g_game->ts / tan(ray->angl);
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
	return (a);
}

t_point			ft_verti_intersect(t_ray *ray)
{
	t_point		a;
	double		x_step;
	double		y_step;

	a.x = floor(g_game->player->x / g_game->ts) * g_game->ts;
	a.x += (ray->is_facing & RIGHT) ? g_game->ts : 0;
	a.y = g_game->player->y + (a.x - g_game->player->x) * tan(ray->angl);
	x_step = g_game->ts * ((ray->is_facing & LEFT) ? -1 : 1);
	y_step = g_game->ts * tan(ray->angl);
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

	ray->is_facing = 0;
	ray->is_facing |= (ray->angl > 0 && ray->angl < PI) ? DOWN : UP;
	ray->is_facing |= (ray->angl > PI / 2 && ray->angl < (3 * PI) / 2)
	? LEFT : RIGHT;
	h_pnt = ft_horis_interst(ray);
	v_pnt = ft_verti_intersect(ray);
	h_dist = (ray->is_facing & HIT_HORIS) ?
	ft_dst_2pnt(g_game->plyr, h_pnt) : INT_MAX;
	v_dist = (ray->is_facing & HIT_VERTI) ?
	ft_dst_2pnt(g_game->plyr, v_pnt) : INT_MAX;
	ray->end = (h_dist < v_dist) ? h_pnt : v_pnt;
	ray->dist = (h_dist < v_dist) ? h_dist : v_dist;
	ray->is_facing &= (h_dist < v_dist) ? ~HIT_VERTI : ~HIT_HORIS;
	if (ray->is_facing & HIT_HORIS)
		ray->data = (ray->is_facing & DOWN) ? 0 : 2;
	else
		ray->data = (ray->is_facing & LEFT) ? 1 : 3;
}
