/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/04 18:45:56 by mochegri         ###   ########.fr       */
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
		mlx_hook(game->win_ptr, 2, 0, key_hook, game);
		mlx_loop(game->mlx_ptr);
	}
	ft_destroy(1, game);
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
