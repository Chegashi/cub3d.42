/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/27 19:11:09 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int			main(int ac, char **av)
{
	if (ac != 2)
		ft_putstr("ereur dargument\n");
	else
	{
		ft_setup(av[1]);
		mlx_key_hook(g_game->win_ptr, key_hook, g_game);
		mlx_hook(g_game->win_ptr, 2, 0, key_hook, g_game);
		mlx_loop(g_game->mlx_ptr);
	}
	//ft_destroy(1, game);
	return (0);
}

int			ft_destroy(int keycode)
{
	printf("%d\n", keycode);
	mlx_destroy_window(g_game->mlx_ptr, g_game->win_ptr);
	exit(1);
	return (0);
}

void		ft_setup(char *file)
{
	// int		sizex;
	// int		sizey;
	int		*resol;

	//mlx_get_screen_size(game->mlx_ptr, &sizex, &sizey);
	// if (game->cube->resolution[0] > sizex || game->cube->resolution[1])
	// {
	// 	game->cube->resolution[0] = sizex;
	// 	game->cube->resolution[1] = sizey;
	// }
	g_game = (t_game*)malloc(sizeof(t_game));
	g_game->cube = ft_read_cub(file);
	resol = g_game->cube->resolution;
	g_game->mlx_ptr = mlx_init();
	g_game->win_ptr = mlx_new_window(g_game->mlx_ptr, resol[0], resol[1], "C");
	g_game->img.img = mlx_new_image(g_game->mlx_ptr, resol[0], resol[1]);
	g_game->player = ft_init_player(g_game->cube);
	g_game->img.addr = mlx_get_data_addr(g_game->img.img, &(g_game->img.bpp),
	&(g_game->img.l_len), &(g_game->img.endian));
	g_game->width = g_game->cube->resolution[0];
	g_game->height = g_game->cube->resolution[1];
	g_game->rays = (t_ray*)malloc(sizeof(t_ray) * (g_game->width + 1));
	g_game->plyr.x = g_game->player->x;
	g_game->plyr.y = g_game->player->y;
	ft_render();
}

void		ft_render()
{
	ft_clean_win();
	ft_raycasting();
	ft_render_wall();
	// ft_render_celing();
	// ft_render_floor();
	// ft_render_sprite();
	ft_render_map();
	ft_render_rays();
	ft_render_player();
	mlx_put_image_to_window(g_game->mlx_ptr, g_game->win_ptr,
	g_game->img.img, 0, 0);
}