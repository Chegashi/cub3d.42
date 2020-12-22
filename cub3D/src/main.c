/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/20 09:18:45 by mochegri         ###   ########.fr       */
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
		//ft_setup();
		//while (game1->is_running)
		//{
		//ft_prosesinput(game1);
		//update()
		//render()
		//}
		game1 = (t_game*)malloc(sizeof(t_game));
		game1->cube = ft_read_cub(av[1]);
		ft_init_game(game1);
		//destroywindows()
	}
 	return 0;
}
//int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
