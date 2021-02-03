/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:50:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/03 19:41:48 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_counters_sprites(void)
{
    int		i;
	int		j;
	int		somme;

	i= -1;
	somme = 0;
	while (++i < g_game->cube->nbr_ligne)
	{
		j = 0;
		while(++j < g_game->cube->nbr_column)
            if (g_game->cube->map[i][j] == '2')
                somme++;
	}
	g_game->sprites.nbr = somme;
}

void	ft_init_sprite(void)
{
	ft_counters_sprites();
	g_game->sprites.order = (int*)malloc(sizeof(int) * g_game->sprites.nbr);
	g_game->sprites.z_buffer = (double*)malloc(sizeof(double) * g_game->width);
	g_game->sprites.texture = g_game->cube->textures[4];
	//g_game->sprites.distance = ()
}