/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/18 16:57:27 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_arg(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		get_err("error \tdargument\n");
	else if (strcmp(av[1] + strlen(av[1]) - 4, ".cub"))
		get_err("error extention map file\n");
	else if (ac == 3 && !ft_strcmp(av[2], "--save"))
		g_save = 1;
	else
		g_save = 0;
}

int		main(int ac, char **av)
{
	ft_check_arg(ac, av);
	ft_setup(av[1]);
	mlx_key_hook(g_game->win_ptr, key_hook, g_game);
	mlx_hook(g_game->win_ptr, 2, 0, key_hook, g_game);
	mlx_hook(g_game->win_ptr, 17, 0, ft_exit, EXIT_SUCCESS);
	mlx_loop(g_game->mlx_ptr);
	return (0);
}

int		ft_destroy(int keycode)
{
	printf("%d\n", keycode);
	mlx_destroy_window(g_game->mlx_ptr, g_game->win_ptr);
	exit(1);
	return (0);
}

void	ft_setup(char *file)
{
	g_game = (t_game*)malloc(sizeof(t_game));
	g_game->mlx_ptr = mlx_init();
	g_game->cube = ft_read_cub(file);
	ft_fill_game();
	ft_render();
}

void	ft_fill_game(void)
{
	int		*resol;

	ft_get_tilesize();
	resol = g_game->cube->resolution;
	g_game->win_ptr = mlx_new_window(g_game->mlx_ptr, resol[0],
	resol[1], "Cub3d");
	g_game->img.img = mlx_new_image(g_game->mlx_ptr, resol[0], resol[1]);
	g_game->player = ft_init_player(g_game->cube);
	g_game->img.addr = mlx_get_data_addr(g_game->img.img,
	&(g_game->img.bpp), &(g_game->img.l_len), &(g_game->img.endian));
	g_game->rays = (t_ray*)malloc(sizeof(t_ray) * (g_game->width + 1));
	g_game->plyr.x = g_game->player->x;
	g_game->plyr.y = g_game->player->y;
	ft_init_sprite();
}
