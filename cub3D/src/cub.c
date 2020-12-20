/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/20 08:07:58 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init_game(t_game *game)
{
    int *resol;
    int sizex;
    int sizey;

    resol = game->cube->resolution;
    game->mlx_ptr = mlx_init();
    //mlx_get_screen_size(game->mlx_ptr, &sizex, &sizey);
    //printf("[%d\n%d\n%d\n",sizex, sizey, t);
    if (resol[0] < sizex || resol[1] < sizey)
    {
        game->cube->resolution[0] = sizex;
        game->cube->resolution[1] = sizey;
    }
	game->win_ptr = mlx_new_window(game->mlx_ptr, resol[0], resol[1], "cub3d");
    game->img.img = mlx_new_image(game->mlx_ptr, resol[0], resol[1]);
    game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp), &(game->img.l_len), &(game->img.endian));
    int i=0,j=0;
    //ft_draw_map(game->cube);
    // int color = 0xff0000;
     while (i++ < 100)
    {
        j = -1;
        while (j++ < 100)
            img_ptr[i * resol[0] + j] = color;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, 0, 0);
    mlx_loop(game->mlx_ptr);
}