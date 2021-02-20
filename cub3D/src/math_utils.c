/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:13:38 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/20 15:39:36 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point			ft_translate_point(t_point p, double x, double y)
{
	p.x += x;
	p.y += y;
	return (p);
}

double			deg_to_rad(double x1)
{
	return (x1 * PI / 180);
}

double			rad_to_deg(double x1)
{
	return (x1 * 180 / PI);
}

double			ft_sprite_angl(double y, double x)
{
	double	angle;

	angle = g_game->player->rotationangle -
	atan2f(y - g_game->plyr.y, x - g_game->plyr.x);
	if (angle < -1 * PI)
		angle += (2 * PI);
	if (angle > PI)
		angle -= (2 * PI);
	return (fabs(angle));
}

void			ft_clean_win(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_game->width)
	{
		j = -1;
		while (++j < g_game->hight)
			my_mlx_pixl_put(&(g_game->img), i, j, 0x0);
	}
}
