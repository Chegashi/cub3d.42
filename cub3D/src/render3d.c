/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:08:20 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/16 18:26:54 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void				ft_render_wall(void)
{
	int		i;
	t_ray	ray;

	i = -1;
	while(++i < g_game->width)
	{
		ray = g_game->rays[i];
		ft_wall_texture(g_game->rays[i], i);
	}

}

void				ft_render_celing(void)
{
	int				i;
	int				color;
	t_point			p1;
	t_point			p2;
	int				*tab;

	i = -1;
	tab = g_game->cube->ceilling_color;
	color = ft_create_trgb(1, tab[0], tab[1], tab[2]);
	while (++i < g_game->cube->resolution[0])
	{
		p1.x = i;
		p1.y = 0;
		p2.x = i;
		p2.y = g_game->rays[i].top_pixel;
		ft_render_line(&(g_game->img), p1, p2, color);
	}
}

void				ft_render_floor(void)
{
	int				i;
	int				*tab;
	int				color;
	t_point			p1;
	t_point			p2;

	i = -1;
	tab = g_game->cube->floor_color;
	color = ft_create_trgb(1, tab[0], tab[1], tab[2]);
	while (++i < g_game->cube->resolution[0])
	{
		p1.x = i;
		p1.y = g_game->rays[i].bottom_pixel;
		p2.x = i;
		p2.y = g_game->height;
		ft_render_line(&(g_game->img), p1, p2, color);
	}
}

int					ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void				ft_wall_texture(t_ray ray, int i)
{
	int				j;
	double			x_off;
	double			y_off;
	double			y_step;
	t_texture		texture;

	texture = g_game->cube->textures[ray.data];
	j = (int)ray.top_pixel;
	x_off = (!fmod(ray.end.x, TILE_SIZE)) ? ray.end.y : ray.end.x;
	x_off = fmod(x_off, TILE_SIZE);
	y_step = texture.hight / ray.wall_h;
	x_off = (x_off / TILE_SIZE) * texture.width;
	y_off = (g_game->height / 2 - ray.wall_h / 2 > 0) ?
	0 : fabs(g_game->height / 2 - ray.wall_h / 2)
	* texture.width / ray.wall_h;
	while (++j < ray.bottom_pixel)
	{
		if (!(x_off < 0 || x_off > texture.width
					|| y_off < 0 || y_off > texture.hight))
			my_mlx_pixel_put(&(g_game->img), i, j, texture.color[(int)(texture.hight
						* (int)y_off + (int)x_off)]);
		y_off += y_step;
	}
}
