/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/30 19:11:44 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if(ac != 2)
		ft_putstr("ereur dargument\n");
	else
	{
		game = ft_setup(game, av[1]);
		// while(game->is_running)
		// {
		ft_prosesinput(game);
		mlx_loop_hook(game->mlx_ptr, ft_update, game);
		 	mlx_loop(game->mlx_ptr);
		//  }
	}
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	//ft_destroy(1, game);
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

t_player	*ft_init_player(t_cub *cub)
{
	t_player *player;

	player = (t_player*)malloc(sizeof(t_player));
	player->x = (cub->player_position[0]) * tile_size;
	player->y = (cub->player_position[1]) * tile_size;
	if (cub->direction == 'N')
		player->rotationAngle = PI * (3 / 2);
	if (cub->direction == 'E')
		player->rotationAngle = 0;
	if (cub->direction == 'S')
		player->rotationAngle = PI / 2;
	if (cub->direction == 'W')
		player->rotationAngle = PI;
	player->turnDirection = 0;
	player->walkDirection = 100;
	player->walkSpeed = 0;
	player->turnSpeed = 45 * (PI / 180);
	return (player);
}

void	ft_prosesinput(t_game *game)
{
	mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_mouse_hook(game->win_ptr, mouse_hook, game);
	mlx_hook(game->win_ptr, 17, 1L<<17, ft_destroy, game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		game->player->x -= cos(game->player->rotationAngle) * 10;
	if (keycode == 0 || keycode == 123)
		game->player->rotationAngle += 0.1;
	if (keycode == 1 || keycode == 125)
		game->player->x += cos(game->player->rotationAngle) * 10;
	if (keycode == 2 || keycode == 124)
		game->player->rotationAngle -= 0.1;
	return 0;
}

int mouse_hook(int button, int x,int y, t_game *game)
{
	if(button == 1)
	{
		game->player->x = x;
		game->player->y = y;
	}
	return 0;
}

int			ft_update(t_game *game)
{
	 mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_render(game);
	return 0;
}

int 		ft_destroy(int keycode, t_game *game)
{
	game->is_running = 0;
	printf("%d\n", keycode);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(1);
	return 0;
}