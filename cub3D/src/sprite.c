/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:50:29 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/09 19:07:46 by mochegri         ###   ########.fr       */
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


void	ft_sort_sprites(void)
{
	int		i;
	int		j;
	double	tmp;
	t_point		p1;

	j = -1;
	while(++j < g_game->sprites.nbr)
	{
		p1.x = g_game->sprites.sprite_tab[j].x;
		p1.y = g_game->sprites.sprite_tab[j].y;
		g_game->sprites.order[j] = j;
		g_game->sprites.sprite_tab[j].distance = ft_dis_2point(p1,g_game->plyr);
	}
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

void	ft_render_sprite(void)
{
	int			i;
	
	t_sprite	sprite;

	i = -1;
	ft_sort_sprites();
	sprite = *(g_game->sprites.sprite_tab);
	while (++i < g_game->sprites.nbr)
	{
		sprite = g_game->sprites.sprite_tab[i];
		sprite.angle = ft_sprite_angl(sprite.y, sprite.x);
		sprite.size = (g_game->width / sprite.distance) * TILE_SIZE;
		sprite.y_offset = g_game->height / 2 - (int)sprite.size / 2;
		sprite.x_offset = (rad_to_deg(sprite.angle
		- g_game->player->rotationangle) * g_game->width)
		/ TILE_SIZE + g_game->width / 2.0f + sprite.size / 2.0f;
		ft_draw_sprites(sprite);
		//printf("dis:%l")
	}
}

void	ft_draw_sprites(t_sprite	sprite)
{
	int	i;
	int j;
	int color;
	t_texture texture;

	i = -1;
	texture = g_game->cube->textures[1];
	i =-1;
	while (++i < sprite.size)
	{
		if (sprite.x_offset + i < 0 || sprite.x_offset + i >= g_game->width ||
		sprite.distance >= g_game->sprites.z_buffer[(int)(sprite.x_offset + i)])
			continue;
		j = -1;
		while(++j < sprite.size)
		{
			if (sprite.y_offset + j <= 0 || sprite.y_offset + j >= g_game->height)
				continue;
			color = texture.color[(int)(TILE_SIZE * ((TILE_SIZE * j / sprite.size) +
					(TILE_SIZE * i / sprite.size)))];
			if(color)
				my_mlx_pixel_put(&(g_game->img), i, j, color);
			//printf("[%d]\t{%d\t%d\t}\n",color, i,j);
		}
	}
}