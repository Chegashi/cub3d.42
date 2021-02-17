/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:09:12 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/17 14:42:52 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>
void	ft_initialize_save(void)
{
	g_game->bitm.w = g_game->width;
	g_game->bitm.he = g_game->height;
	g_game->bitm.bc = 32;
	g_game->bitm.imgs = g_game->bitm.w * g_game->bitm.he * 4;
	g_game->bitm.bs = 40;
	g_game->bitm.bob = 54;
	g_game->bitm.fs = 54 + g_game->bitm.imgs;
	g_game->bitm.bp = 1;
	if (!(g_game->bitm.buf = malloc(g_game->bitm.imgs)))
	get_err("error\tmemory problem\n");
	g_game->bitm.ro = g_game->bitm.he - 1;
	g_game->bitm.co = 0;
}

void	ft_header(void)
{
	ft_memcpy(g_game->bitm.h, "BM", 2);
	ft_memcpy(g_game->bitm.h + 2, &g_game->bitm.fs, 4);
	ft_memcpy(g_game->bitm.h + 10, &g_game->bitm.bob, 4);
	ft_memcpy(g_game->bitm.h + 14, &g_game->bitm.bs, 4);
	ft_memcpy(g_game->bitm.h + 18, &g_game->bitm.w, 4);
	ft_memcpy(g_game->bitm.h + 22, &g_game->bitm.he, 4);
	ft_memcpy(g_game->bitm.h + 26, &g_game->bitm.bp, 2);
	ft_memcpy(g_game->bitm.h + 28, &g_game->bitm.bc, 2);
	ft_memcpy(g_game->bitm.h + 34, &g_game->bitm.imgs, 4);
}

int		ft_save(void)
{
	int *pixel;
	int pos;
	//prob
	bzero(g_game->bitm.h, 54);
	ft_initialize_save();
	ft_header();
	g_game->bitm.fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0644);
	write(g_game->bitm.fd, g_game->bitm.h, 54);
	while (g_game->bitm.ro > -1)
	{
		while (g_game->bitm.co < g_game->width)
		{
			pos = g_game->bitm.ro * g_game->bitm.w + g_game->bitm.co;
			pixel = (int *)(g_game->img.addr) + pos;
			write(g_game->bitm.fd, pixel, 4);
			g_game->bitm.co++;
		}
		g_game->bitm.ro--;
		g_game->bitm.co = 0;
	}
	close(g_game->bitm.fd);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_save_file(void)
{
	g_game->bitm.fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0644);
	close(g_game->bitm.fd);
	free(g_game->bitm.buf);
}

