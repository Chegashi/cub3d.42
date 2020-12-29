/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rende.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:00:47 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/29 19:38:06 by mochegri         ###   ########.fr       */
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
	int k;
	double xinc; 
    double yinc;
    double steps;

	steps = (fabs(p2.x - p1.x) > fabs(p2.y - p1.y)) ? fabs(p2.x - p1.x)
    :fabs(p2.y - p1.y);
	xinc = (p2.x - p1.x) / steps;
	yinc = (p2.y - p1.y) / steps;
	k = -1;
	while (++k < steps)
	{
		p1.x += xinc;
		p1.y += yinc; 
		my_mlx_pixel_put(data, p1.x, p1.y, color);
	}
}

void	ft_render(t_game *game)
{
	ft_draw_map(game);
    //ft_render_rays();
	//ft_render_player(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}

void    draw_rect(t_data *data, t_square s, int color)                                                                                                                                
{
    int i;
    int j;
    
    i = s.x;
    j = s.y;
    // while (i++ < s.x + s.lent)
    // {
    //     j = s.y;
    //     while (j++ < s.y + s.lent)
    //     {
    //         my_mlx_pixel_put(data,i,j,color);
    //         
    //     }
    // }
    printf("%d,%d,%d\n ",s.x,s.y , s.lent);
    printf("%d,%d", color, data->l_len);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}