/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:50:22 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/20 14:20:06 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_sprite_config(t_sprite *sprite)
{
	double		per_dist;
	double		sprite_ngl;

	per_dist = sprite->dist * cos(sprite->angle);
	sprite->size = (g_game->ts / per_dist) * g_game->dis_plan;
	sprite->size *= 3;
	sprite->top_y = (g_game->height / 2) - (sprite->size / 2) + g_game->player->z;
	sprite->top_y *= (sprite->top_y < 0) ? 0 : 1;
	sprite->bottom_y = (g_game->height / 2) + (sprite->size / 2) + g_game->player->z;
	sprite->bottom_y = (sprite->top_y > g_game->height)
		? g_game->height : sprite->bottom_y;
	sprite_ngl = atan2f(sprite->y - g_game->plyr.y, sprite->x - g_game->plyr.x)
		- g_game->player->rotationangle;
	sprite->scren_pos = (tan(sprite_ngl) * g_game->dis_plan);
	sprite->scren_pos *= -3;
	sprite->leeft_x = g_game->width / 2 - sprite->scren_pos
		- (sprite->size / 2);
	sprite->right_x = sprite->leeft_x + sprite->size;
}

void			ft_put_pixel_sprit(t_sprite sprite, t_texture txt, int i, int j)
{
	int			dist_top;
	int			color;

	if (i > 0 && i < g_game->width && j > 0 && j < g_game->height)
	{
		dist_top = j + sprite.size / 2 - g_game->height / 2;
		sprite.y_offset = dist_top * (txt.hight / sprite.size);
		color = txt.color[(txt.width * (int)sprite.y_offset)
			+ (int)sprite.x_offset];
		if (color && g_game->rays[i].dist > sprite.dist)
			my_mlx_pixel_put(&(g_game->img), i, j, color);
	}
}

void			ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}
