/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/16 02:42:10 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
int main(int ac, char **av)
{
	t_game	*game1;

	if(ac != 2)
		ft_putstr("ereur dargument\n");
	else
	{
		game1 = (t_game*)malloc(sizeof(t_game));
		game1->cube = ft_read_cub(av[1]);
		print_cub(game1->cube);
	}
 	return 0;
}
