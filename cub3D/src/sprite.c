/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:50:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/06 18:28:40 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_counters_sprites(void)
{
    int		i;
	int		j;
	int		somme;

	i= 0;
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
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	ft_counters_sprites();
	g_game->sprites.sprite_tab = (t_sprite*)malloc(sizeof(t_sprite) *
	g_game->sprites.nbr);
	g_game->sprites.order = (int*)malloc(sizeof(int) * g_game->sprites.nbr);
	g_game->sprites.z_buffer = (double*)malloc(sizeof(double) * g_game->width);
	while (++i < g_game->cube->nbr_ligne)
	{
		j = 0;
		while(++j < g_game->cube->nbr_column)
            if (g_game->cube->map[i][j] == '2')
            {
				g_game->sprites.sprite_tab[k].x = j * TILE_SIZE;
				g_game->sprites.sprite_tab[k].y = i * TILE_SIZE;
				g_game->sprites.sprite_tab[k].index = k;
				k++;
			}
	}
}

void		ft_sprite_distance(void)
{
	int		i;
	t_point			p1;

	i = -1;
	while (++i < g_game->sprites.nbr)
	{
		p1.x = g_game->sprites.sprite_tab[i].x;
		p1.y = g_game->sprites.sprite_tab[i].y;
		g_game->sprites.sprite_tab[i].distance = ft_dis_2point(p1,g_game->plyr);
	}
	ft_sort_sprites();
	ft_fill_z_buffer();
	ft_highsprites();
	//ft_width_sprite();
}

void	ft_sort_sprites(void)
{
	int		i;
	int		j;
	double	tmp;

	j = -1;
	while(++j < g_game->sprites.nbr)
		g_game->sprites.order[j] = j;
	i = g_game->sprites.nbr;
	while (--i >= 0)
	{
		j = -1;
		while (++j <= i - 1)
			if (g_game->sprites.sprite_tab[j].distance
			< g_game->sprites.sprite_tab[j + 1].distance)
			{
				tmp = g_game->sprites.order[j + 1];
				g_game->sprites.order[j + 1] = g_game->sprites.order[j];
				g_game->sprites.order[j] = tmp;
			}
	}
}

void	ft_fill_z_buffer(void)
{
	int i;

	i = -1;
	while (++i  < g_game->width)
		g_game->sprites.z_buffer[i] = g_game->rays[i].dist;
}

void	ft_highsprites(void)
{
	double		dis_wall_p;
	int			i;

	i = -1;
	while (++i < g_game->sprites.nbr)
	{
		dis_wall_p = (g_game->cube->resolution[1] / 2) * tan(FOV_V / 2);
		g_game->sprites.sprite_tab[i].hight = (TILE_SIZE
		/ g_game->sprites.sprite_tab[i].distance) * dis_wall_p;
		g_game->rays[i].wall_start = ((g_game->cube->resolution[1] / 2)
				- g_game->sprites.sprite_tab[i].hight / 2);
	}
}

void			ft_calculate_sprite(void)
{
	
}