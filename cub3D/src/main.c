/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/05 06:28:03 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int		win_init(char *map_name)
{

}

int main(int ac , char **av)
{
	
	t_game game;
	game = ft_win_init(char *s);
	ft_setup();
	while(game->runing)
	{
		prossesInput();
		update();
		render()
	}
	return 0;
}
