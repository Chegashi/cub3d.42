/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/26 05:37:16 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if(ac != 2)
		ft_putstr("ereur dargument\n");
	else
	{
		game = ft_setup(game, av[1]);
		mlx_loop(game->mlx_ptr);
		//while(game->is_running)
		// {
		// 	ft_prosesinput(game);
		// 	ft_update(game);
		// 	ft_render(game);
		// }
	}
	//ft_destroy(game);
 	return 0;
}

t_game *ft_setup(t_game *game, char *file)
{
	int		sizex;
    int		sizey;
    int		*resol;
	
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
	ft_draw_map(game);
	return(game);
}

t_player	*ft_init_player(t_cub *cub)
{
	t_player *player;
	
	player = (t_player*)malloc(sizeof(t_player));
	player->x = (cub->player_position[0]) * tile_size;
	player->y = (cub->player_position[1]) * tile_size;
	if (cub->direction == 'N')
		player->rotationAngle = PI / 2;
	if (cub->direction == 'E')
		player->rotationAngle = 0;
	if (cub->direction == 'S')
		player->rotationAngle = PI * (3 / 4) ;
	if (cub->direction == 'O')
		player->rotationAngle = PI;
	player->turnDirection = 0;
	player->walkDirection = 100;
	player->walkSpeed = 0;
	player->turnSpeed = 45 * (PI / 180);
	return (player);
}
void	ft_render_player(t_game *game1)
{
	draw_rect(&(game1->img), (game1->player->y),(game1->player->x), tile_size, tile_size, 0xfff68f);
	mlx_put_image_to_window(game1->mlx_ptr, game1->win_ptr, game1->img.img, 0, 0);
}
void	ft_prosesinput(t_game *game)
{
	///f//
}

void	ft_update(t_game *game)
{
	//e
}

void	ft_render(t_game *game)
{
	///d
}
void 		ft_destroy(t_game *game)
{
	///e
}