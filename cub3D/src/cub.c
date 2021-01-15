/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:55:37 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/14 17:59:49 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void		ft_draw_map(t_game *game)
{
    int i;
    int j;
    int tileX;
    int tileY;
    int color;
    t_square sqr;

    i = -1;
    while(++i < game->cube->nbr_ligne)
    {
        j = -1;
        while (++j < game->cube->nbr_column)
        {
            color = 0x00;
            tileX = j * tile_size;
            tileY = i * tile_size;
            color = (game->cube->map[i][j] == '1') ? 0x8b1c62 : 0xff7256;
            if(game->cube->map[i][j] != ' ')
            {
                sqr.x = tileX * map_coef;
                sqr.y = tileY * map_coef;
                sqr.lent = tile_size * map_coef;
                draw_rect(&(game->img), sqr, color);
            }
        }
    }
}

int			ft_update(t_player *p , t_game *game)
{
	float move;
    t_player *new_player;
    
    new_player = (t_player *)malloc(sizeof(t_player));
    *new_player = *p;
	move = p->walkDirection * p->walkSpeed;
	new_player->x += cos(p->rotationAngle) * move;
	new_player->y += sin(p->rotationAngle) * move;
    new_player->rotationAngle += p->turnDirection * p->turnSpeed;
    ft_normilised(&(new_player->rotationAngle));
    if(ft_is_wall(new_player->x, new_player->y, game))
        *p = *new_player;
    free(new_player);
	return 0;
}

t_game		*ft_setup(t_game *game, char *file)
{
	// int		sizex;
    // int		sizey;
    int		*resol;

	//mlx_get_screen_size(game->mlx_ptr, sizex, sizey);
	// if(game->cube->resolution[0] > sizex || game->cube->resolution[1])
	// {
	// 	game->cube->resolution[0] = sizex;
	// 	game->cube->resolution[1] = sizey;
	// }
	game = (t_game*)malloc(sizeof(t_game));
	if (!game)
		return(NULL);
	game->cube = ft_read_cub(file);
	resol = game->cube->resolution;
	game->is_running = game->cube->valide;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, resol[0], resol[1], "Salon");
	game->img.img = mlx_new_image(game->mlx_ptr,resol[0], resol[1]);
	game->player = ft_init_player(game->cube);
	game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp),
	&(game->img.l_len), &(game->img.endian));
	ft_render(game);
	return(game);
}
int ft_is_wall(float x, float y, t_game *game)
{
    int x_index;
    int y_index;

    x_index = floor(x) / tile_size;
    y_index = floor(y) / tile_size;
    if(x < 0 || y < 0 || x > game->cube->resolution[0] || y > game->cube->resolution[1])
        return (0);
    return(game->cube->map[y_index][x_index] == '0');
}