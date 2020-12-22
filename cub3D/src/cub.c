/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/22 20:14:12 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init_game(t_game *game)
{
    int *resol;
    int sizex;
    int sizey;

    resol = game->cube->resolution;
    game->mlx_ptr = mlx_init();int t =0;
    mlx_get_screen_size(game->mlx_ptr, &sizex, &sizey);
    if (resol[0] > sizex || resol[1] > sizey)
    {
        game->cube->resolution[0] = sizex;
        game->cube->resolution[1] = sizey;
    }
	game->win_ptr = mlx_new_window(game->mlx_ptr, resol[0], resol[1], "cub3d");
    game->img.img = mlx_new_image(game->mlx_ptr,resol[0], resol[1]);
    game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp), &(game->img.l_len), &(game->img.endian));
    ft_draw_map(game);    
    mlx_loop(game->mlx_ptr);
}

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
    double t = 1;
    int tileX;
    int tileY;
    int tile_size = 8;
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
                draw_rect(&(game->img), tileX*t,tileY*t,tile_size*t, tile_size*t,color);
        }
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}