/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/20 19:22:49 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int			main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		ft_putstr("ereur dargument\n");
	else
	{
		game = ft_setup(game, av[1]);
		mlx_key_hook(game->win_ptr, key_hook, game);
		mlx_hook(game->win_ptr, 2, 0, key_hook, game);
		mlx_loop(game->mlx_ptr);
	}
	//ft_destroy(1, game);
	return (0);
}

int			ft_destroy(int keycode, t_game *game)
{
	game->is_running = 0;
	printf("%d\n", keycode);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(1);
	return (0);
}

t_game		*ft_setup(t_game *game, char *file)
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
	game = (t_game*)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->cube = ft_read_cub(file);
	resol = game->cube->resolution;
	game->is_running = game->cube->valide;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, resol[0], resol[1], "Salon");
	game->img.img = mlx_new_image(game->mlx_ptr, resol[0], resol[1]);
	game->player = ft_init_player(game->cube);
	game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp),
	&(game->img.l_len), &(game->img.endian));
	game->img.width = game->cube->resolution[0];
	game->img.height = game->cube->resolution[1];
	ft_render(game);
	return (game);
}
