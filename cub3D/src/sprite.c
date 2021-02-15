/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:50:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/15 18:05:16 by mochegri         ###   ########.fr       */
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
	while (++i < g_game->cube->nbr_ligne)
	{
		j = 0;
		while(++j < g_game->cube->nbr_column)
            if (g_game->cube->map[i][j] == '2')
            {
				g_game->sprites.sprite_tab[k].x = (j + 1 / 2 )* TILE_SIZE;
				g_game->sprites.sprite_tab[k].y = (i + 1 / 2 )* TILE_SIZE;
				k++;
			}
	}
}

void	ft_sort_sprites(void)
{
	int		i;
	int		j;
	t_sprite	tmp;
	t_point		p1;

	j = -1;
	while(++j < g_game->sprites.nbr)
	{
		p1.x = g_game->sprites.sprite_tab[j].x;
		p1.y = g_game->sprites.sprite_tab[j].y;
		g_game->sprites.sprite_tab[j].distance = ft_dst_2pnt(p1,g_game->plyr) - TILE_SIZE/2;
	}
	i = g_game->sprites.nbr;
	while (--i >= 0)
	{
		j = -1;
		while (++j <= i - 1)
			if (g_game->sprites.sprite_tab[j].distance
			< g_game->sprites.sprite_tab[j + 1].distance)
			{
				tmp = g_game->sprites.sprite_tab[j + 1];
				g_game->sprites.sprite_tab[j + 1] = g_game->sprites.sprite_tab[j];
				g_game->sprites.sprite_tab[j] = tmp;
			}
	}
}

void	ft_render_sprite(void)
{
	int			i;
	double		per_distance;
	t_sprite	*sprite;
	double	sprite_ngl;
	t_point p1,p2;
	i = -1;
	ft_sort_sprites();
	sprite = (g_game->sprites.sprite_tab);
	while (++i < g_game->sprites.nbr)
	{
		sprite = g_game->sprites.sprite_tab + i;
		sprite->angle = ft_sprite_angl(sprite->y, sprite->x);
		sprite->is_visible = (sprite->angle < (FOV_H / 2) + 0.05 ) ? 1 : 0;
		
		if(sprite->is_visible)
		{
			per_distance = sprite->distance * cos(sprite->angle);
			sprite->size = (TILE_SIZE / per_distance) * g_game->dis_plan;
			sprite->size *= 3;
			sprite->top_y = (g_game->height / 2) - (sprite->size / 2);
			sprite->top_y *= (sprite->top_y < 0) ? 0 : 1;
			sprite->bottom_y = (g_game->height / 2) + (sprite->size / 2);
			sprite->bottom_y = (sprite->top_y > g_game->height) ? g_game->height : sprite->bottom_y;
			sprite_ngl = atan2f(sprite->y - g_game->plyr.y, sprite->x - g_game->plyr.x) - g_game->player->rotationangle;
			sprite->scren_pos = tan(sprite_ngl) * g_game->dis_plan;
			sprite->leeft_x = g_game->width /2 + sprite->scren_pos;
			sprite->right_x = sprite->leeft_x + sprite->size;
			p1.x = 0;
			p2.x = 0;
			p1.y = sprite->top_y;
			p2.y = sprite->bottom_y;
			printf("angl:%lf\t\tpos_x:%lf\t\tply:[%lf,%lf]\tpos[%d,%d]\n",
			rad_to_deg(sprite->angle), sprite->scren_pos, g_game->plyr.x,g_game->plyr.y,sprite->x,sprite->y);
			ft_draw_sprites(*sprite);
		}
		
		//printf("ang:%lf\t\tis_v:%d\n", sprite->angle, sprite->is_visible);
	}
}

void	ft_draw_sprites(t_sprite	sprite)
{
	int	i;
	int j;
	int color;
	int dist_top;
	t_texture texture;

	i = sprite.leeft_x - 1;
	texture = g_game->cube->textures[4];
	while (++i < sprite.right_x)
	{
		sprite.x_offset = (i - sprite.leeft_x) * (texture.width / sprite.size);
		j = sprite.top_y - 1;
		if(sprite.x_offset < 0)
			sprite.x_offset = 0;
		while(++j < sprite.bottom_y)
		{
			if (i > 0 && i < g_game->width && j > 0 && j < g_game->height)
			{
				dist_top = j + sprite.size / 2 - g_game->height / 2;
				sprite.y_offset = dist_top * (texture.hight /sprite.size);
				color = texture.color[(texture.width * sprite.y_offset) + sprite.x_offset];
				if(color)
				//printf("%d\t%d\t\t[%d, %d]\n",sprite.x_offset,sprite.y_offset , texture.hight, texture.width);
				my_mlx_pixel_put(&(g_game->img), i, j, color);
		
		}	
		
		}
	}
}