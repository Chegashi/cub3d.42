/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/24 19:38:19 by mochegri         ###   ########.fr       */
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
	if (x < 0 || y < 0 || x > g_game->width || y > g_game->hight)
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
	g_game->hight = g_game->cube->resolution[1];
	if (g_game->width > sizex || g_game->hight > sizey)
	{
		g_game->width = sizex;
		g_game->hight = sizey;
	}
	res = (g_game->width < g_game->hight) ? g_game->width : g_game->hight;
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
	if (BONUS)
	{
		ft_render_map();
		ft_render_rays();
		ft_render_player();
		ft_rendr_sp_map();
		ft_render_scoop();
	}
	if (g_save)
		ft_scren_shot();
	mlx_put_image_to_window(g_game->mlx_ptr, g_game->win_ptr,
		g_game->img.img, 0, 0);
}

int		ft_exit(int i)
{
	mlx_destroy_image(g_game->mlx_ptr, g_game->img.img);
	ft_destroy_cub(g_game->cube);
	free(g_game->player);
	free(g_game->rays);
	free(g_game->sprites.tab);
	free(g_game);
	exit(i);
}

void	ft_render_scoop(void)
{
	t_point	p[9];
	t_point c;

	c.x = g_game->width / 2;
	c.y = g_game->hight / 2;
	p[1].x = c.x;
	p[1].y = c.y - 40;
	p[2].x = c.x;
	p[2].y = c.y - 20;
	p[3].x = c.x;
	p[3].y = c.y + 40;
	p[4].x = c.x;
	p[4].y = c.y + 20;
	p[5].x = c.x - 20;
	p[5].y = c.y;
	p[6].x = c.x - 40;
	p[6].y = c.y;
	p[7].x = c.x + 20;
	p[7].y = c.y;
	p[8].x = c.x + 40;
	p[8].y = c.y;
	ft_render_line(&(g_game->img), p[1], p[2], 0xff0000);
	ft_render_line(&(g_game->img), p[3], p[4], 0xff0000);
	ft_render_line(&(g_game->img), p[5], p[6], 0xff0000);
	ft_render_line(&(g_game->img), p[7], p[8], 0xff0000);
}
