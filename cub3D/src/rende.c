/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rende.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:00:47 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/19 12:46:39 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		ft_draw_disque(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	int r;

	r = 5;
	i = x - r;
	while (++i < x + r)
	{
		j = y - r;
		while (++j < y + r)
		{
			if (pow(i - x, 2) + pow(j - y, 2) < pow(r, 2))
				my_mlx_pixel_put(data, i, j, color);
		}
	}
}

void		ft_render_line(t_data *data, t_point p1, t_point p2, int color)
{
	int		k;
	float	xinc;
	float	yinc;
	float	steps;

	steps = ft_max(fabs(p1.x - p2.x), fabs(p1.y - p2.y));
	xinc = (p2.x - p1.x) / (float)steps;
	yinc = (p2.y - p1.y) / (float)steps;
	k = -1;
	while (++k < steps)
	{
		my_mlx_pixel_put(data, p1.x * MAP_COEF, p1.y * MAP_COEF, color);
		p1.x += xinc;
		p1.y += yinc;
	}
}

void		ft_render(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_draw_map(game);
	ft_render_rays(game);
	ft_render_player(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}

void		draw_rect(t_data *data, t_square s)
{
	int i;
	int j;

	i = s.x - 1;
	while (++i < s.x + s.lent)
	{
		j = s.y - 1;
		while (++j < s.y + s.lent)
			my_mlx_pixel_put(data, i, j, (i == s.x || j == s.y)
			? 0x00 : s.color);
	}
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
