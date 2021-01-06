/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rende.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:00:47 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/06 19:19:58 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void    ft_draw_disque(t_data *data, int x, int y, int r, int color)
{
	int i;
	int j;

	i = x - r;
	while (++i < x + r)
	{
		j = y - r;
		while (++j < y + r)
		{
			if (pow(i - x, 2) + pow(j - y, 2) < pow(r, 2))
				my_mlx_pixel_put(data,i,j,color);
		}
	}
}

void	ft_render_line(t_data *data, t_point p1, t_point p2, int color)
{
	int		k;
	float	xinc;
	float	yinc;
	float	steps;

	steps = (fabs(p1.x - p2.x) > fabs(p1.y - p2.y)) ? fabs(p1.x - p2.x) : fabs(p1.y - p2.y);
	xinc = (p2.x - p1.x) / (float)steps;
	yinc = (p2.y - p1.y) / (float)steps;
	k = -1;
	while (++k < steps)
	{
		my_mlx_pixel_put(data, p1.y * map_coef, p1.x * map_coef, color);
		p1.x += xinc;
		p1.y += yinc; 
	}
}

void	ft_render(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_draw_map(game);
    ft_render_rays(game);
	ft_render_player(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}

void    draw_rect(t_data *data, t_square s, int color)                                                                                                                                
{
	int i;
	int j;
    
    i = s.x;
    j = s.y;
    while (i++ < s.x + s.lent)
    {
        j = s.y;
        while (j++ < s.y + s.lent)
            my_mlx_pixel_put(data,i,j,color);
    }
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	ft_render_rays(t_game *game)
{
	float angl;
	int clomn_id;
	t_point p;
	t_point p2;

	p.x = game->player->x;
	p.y = game->player->y;
	clomn_id = -1;
	angl = game->player->rotationAngle - FOV / 2;
	// while (clomn_id++ < game->cube->resolution[0])
	// {
	// 	p2.x = p.x + cos(angl) * 30;
	// 	p2.y = p.y + sin(angl) * 30;
		ft_render_line(&(game->img), p, p2, 0x11223344);
	// 	angl += FOV / game->cube->resolution[0];
	// }
}
