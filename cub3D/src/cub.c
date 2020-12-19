/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/18 23:10:02 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init_game(t_game *game)
{
    int resol[] = {1000, 720};
    int i = -1, j=-1;
    //resol = game->cube->resolution;
    game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, resol[0], resol[1], "cub3d");
    int bpp, size_line, endian;
    
    void *img = mlx_new_image(game->mlx_ptr, resol[0], resol[1]);
    int *img_ptr = (int*)mlx_get_data_addr(img, &bpp, &size_line, &endian);
    int color = 0xff0000;
    int width = resol[0];
    while (i++ < 100)
    {
        j = -1;
        while (j++ < 100)
            img_ptr[i * resol[0] + j] = color;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, 0, 0);
    mlx_loop(game->mlx_ptr);
}

//[ddabcd     ]
//[dcbad      ]