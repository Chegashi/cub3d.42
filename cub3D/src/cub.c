/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/19 19:01:50 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		ft_isasprite(double x, double y)
{
	int			x_index;
	int			y_index;

	x_index = floor(x) / g_game->ts;
	y_index = floor(y) / g_game->ts;
	if (x < 0 || y < 0 || x > g_game->cube->resolution[0]
			|| y > g_game->cube->resolution[1])
		return (0);
	return (g_game->cube->map[y_index][x_index] == '2');
}

void	ft_get_tilesize(void)
{
	int		res;
	int		rows;
	int		sizex;
	int		sizey;

	mlx_get_screen_size(g_game->mlx_ptr, &sizex, &sizey);
	g_game->width = g_game->cube->resolution[0];
	g_game->height = g_game->cube->resolution[1];
	if (g_game->cube->resolution[0] > sizex
	|| g_game->cube->resolution[1] > sizey)
	{
		g_game->width = sizex;
		g_game->height = sizey;
	}
	if (g_game->cube->resolution[0] < 500
	|| g_game->cube->resolution[1] < 355)
	{
		g_game->width = 500;
		g_game->height = 355;
	}
	res = (g_game->width < g_game->height) ? g_game->width : g_game->height;
	rows = (g_game->cube->nbr_column > g_game->cube->nbr_ligne)
	? g_game->cube->nbr_column : g_game->cube->nbr_ligne;
	g_game->ts = res / rows;
}

void	ft_render(void)
{
	ft_clean_win();
	ft_raycasting();
	ft_render_celing();
	ft_render_wall();
	ft_render_floor();
	ft_render_sprite();
	if (g_save)
		ft_scren_shot();
	mlx_put_image_to_window(g_game->mlx_ptr, g_game->win_ptr,
		g_game->img.img, 0, 0);
}

int		ft_exit(int i)
{
	mlx_destroy_image(g_game->mlx_ptr, g_game->img.img);
	exit(i);
}
