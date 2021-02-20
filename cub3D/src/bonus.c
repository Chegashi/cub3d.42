/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:42:36 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/20 18:19:18 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_bonus(void)
{
	ft_render_map();
}

void			ft_render_map(void)
{
	int			i;
	int			j;
	int			tilex;
	int			tiley;
	t_square	sqr;

	i = -1;
	while (++i < g_game->cube->nbr_ligne)
	{
		j = -1;
		while (++j < g_game->cube->nbr_column)
		{
			tilex = j * g_game->ts * COEF;
			tiley = i * g_game->ts * COEF;
			sqr.color = (g_game->cube->map[i][j] == '1') ? 0x8b1c62 : 0xff7256;
			if (g_game->cube->map[i][j] != ' ')
			{
				sqr.x = tilex;
				sqr.y = tiley;
				sqr.lent = g_game->ts;
				draw_rect(&(g_game->img), sqr);
			}
		}
	}
}

void			ft_render_rays(void)
{
	int		i;
	t_point	p1;
	t_point p2;

	i = -1;
	while (++i < g_game->width)
	{
		p1.x = g_game->plyr.x * COEF;
		p1.y = g_game->plyr.y * COEF;
		p2.x = (g_game->rays[i].end.x) * COEF;
		p2.y = g_game->rays[i].end.y * COEF;
		ft_render_line(&(g_game->img), p1, p2, 0xffff00);
	}
}

void			ft_rendr_sp_map(void)
{
	int			i;
	int			tilex;
	int			tiley;
	t_square	sqr;

	i = -1;
	while (++i < g_game->sprites.nbr)
	{
		tilex = g_game->sprites.tab[i].x - g_game->ts / 2;
		tiley = g_game->sprites.tab[i].y - g_game->ts / 2;
		sqr.color = (g_game->sprites.tab[i].is_visible) ? 0xffff : 0x660;
		sqr.x = tilex * COEF;
		sqr.y = tiley * COEF;
		sqr.lent = g_game->ts * COEF;
		draw_rect(&(g_game->img), sqr);
	}
}

