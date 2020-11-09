/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/07 00:47:10 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main(int ac, char **av)
{
	t_game 	*game;

	game = ft_win_init(av[1]);
	ft_setup();
//	while(game->running)
//	{
//		prossesInput();
//		update();
//		render()
//	}
	mlx_loop(game->mlx_ptr);
	return 0;
}
