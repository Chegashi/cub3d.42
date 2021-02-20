/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rende.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:00:47 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/20 15:39:36 by mochegri         ###   ########.fr       */
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
				my_mlx_pixl_put(data, i, j, color);
		}
	}
}

void		ft_render_line(t_data *data, t_point p1, t_point p2, int color)
{
	int		k;
	double	xinc;
	double	yinc;
	double	steps;

	steps = ft_max(fabs(p1.x - p2.x), fabs(p1.y - p2.y));
	xinc = (p2.x - p1.x) / (double)steps;
	yinc = (p2.y - p1.y) / (double)steps;
	k = -1;
	while (++k < steps)
	{
		my_mlx_pixl_put(data, p1.x, p1.y, color);
		p1.x += xinc;
		p1.y += yinc;
	}
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
			my_mlx_pixl_put(data, i, j, s.color);
	}
}

void		my_mlx_pixl_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || y <= 0 || x >= g_game->width || y >= g_game->hight)
		return ;
	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void		ft_render_g_rect(t_data *data, t_rectangle rect)
{
	int i;
	int j;

	i = rect.x;
	while (i < rect.x + rect.lent_x)
	{
		j = rect.y;
		while (j < rect.y + rect.lent_y)
		{
			my_mlx_pixl_put(data, i, j, rect.color);
			j++;
		}
		i++;
	}
}
