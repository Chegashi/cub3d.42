/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:50:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/18 18:31:26 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_counters_sprites(void)
{
	int			i;
	int			j;
	int			somme;

	i = 0;
	somme = 0;
	while (++i < g_game->cube->nbr_ligne)
	{
		j = 0;
		while (++j < g_game->cube->nbr_column)
			if (g_game->cube->map[i][j] == '2')
				somme++;
	}
	g_game->sprites.nbr = somme;
}

void			ft_init_sprite(void)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	ft_counters_sprites();
	g_game->sprites.tab = (t_sprite*)malloc(sizeof(t_sprite) *
	g_game->sprites.nbr);
	while (++i < g_game->cube->nbr_ligne)
	{
		j = 0;
		while (++j < g_game->cube->nbr_column)
			if (g_game->cube->map[i][j] == '2')
			{
				g_game->sprites.tab[k].x = (j + 1. / 2) * g_game->ts;
				g_game->sprites.tab[k].y = (i + 1. / 2) * g_game->ts;
				k++;
			}
	}
}

void			ft_sort_sprites(void)
{
	int			i;
	int			j;
	t_sprite	tmp;
	t_point		p1;

	j = -1;
	while (++j < g_game->sprites.nbr)
	{
		p1.x = g_game->sprites.tab[j].x;
		p1.y = g_game->sprites.tab[j].y;
		g_game->sprites.tab[j].dist = ft_dst_2pnt(p1, g_game->plyr);
	}
	i = g_game->sprites.nbr;
	while (--i >= 0)
	{
		j = -1;
		while (++j <= i - 1)
			if (g_game->sprites.tab[j].dist < g_game->sprites.tab[j + 1].dist)
			{
				tmp = g_game->sprites.tab[j + 1];
				g_game->sprites.tab[j + 1] = g_game->sprites.tab[j];
				g_game->sprites.tab[j] = tmp;
			}
	}
}

void			ft_render_sprite(void)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	ft_sort_sprites();
	sprite = (g_game->sprites.tab);
	while (++i < g_game->sprites.nbr)
	{
		sprite = g_game->sprites.tab + i;
		sprite->angle = ft_sprite_angl(sprite->y, sprite->x);
		sprite->is_visible = (sprite->angle <= (FOV / 2)) ? 1 : 0;
		if (sprite->is_visible)
		{
			ft_sprite_config(sprite);
			ft_draw_sprites(sprite);
		}
	}
}

void			ft_draw_sprites(t_sprite *sprite)
{
	int			i;
	int			j;
	t_texture	texture;

	texture = g_game->cube->textures[4];
	i = sprite->leeft_x - 1;
	while (++i < sprite->right_x)
	{
		sprite->x_offset = (i - sprite->leeft_x)
			* (texture.width / sprite->size);
		j = sprite->top_y - 1;
		sprite->x_offset *= (sprite->x_offset < 0) ? 0 : 1;
		while (++j < sprite->bottom_y)
			ft_put_pixel_sprit(*sprite, texture, i, j);
	}
}
