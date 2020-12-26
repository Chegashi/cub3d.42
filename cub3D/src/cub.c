/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/26 05:36:33 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void    draw_rect(t_data *data, int x, int y,int lentx, int lenty, int color)
{
    int i=x,j=y;
    while (i++ < x + lentx)
    {
      j = y;
       while (j++ < y + lenty)
        my_mlx_pixel_put(data,i,j,color);
    }
}
void		ft_draw_map(t_game *game)
{
    char **map;
    int i;
    int j;
    int tileX;
    int tileY;

    i = -1;
    map = game->cube->map;
    while(++i < game->cube->nbr_ligne)
    {
        j = -1;
        while (++j < game->cube->nbr_column)
        {
            int color = 0x00;
            tileX = j * tile_size;
            tileY = i * tile_size;
            if (game->cube->map[i][j] == '1')
                color = 0x8b1c62;
            else if (ft_isin("20NSEO", game->cube->map[i][j]))
                color = 0xff7256;
            if(game->cube->map[i][j] != ' ')
                draw_rect(&(game->img), tileX * map_coef, tileY *map_coef,
                tile_size * map_coef, tile_size * map_coef ,color);
        }
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}