/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/24 12:07:52 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game	*game1;

	game1 = NULL;
	if(ac != 2)
		ft_putstr("ereur dargument\n");
	else
	{
		game1 = ft_setup(game1, av[1]);
		ft_draw_map(game1);
		ft_render_player(game1);
	//	while(game1->is_running)
	//	{
			//ft_draw_map(game);    
    		//mlx_loop(game->mlx_ptr);
			//ft_prosesinput(game1);
			//update()
			//render()    
    	mlx_loop(game1->mlx_ptr);
	//	}
	}
 	return 0;
}

t_game *ft_setup(t_game *game1, char *file)
{
	game1 = (t_game*)malloc(sizeof(t_game));
	game1->cube = ft_read_cub(file);
	game1->is_running = game1->cube->valide;
	ft_init_game(game1);
	game1->player = ft_init_player(game1->cube);
	return(game1);
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
	printf("[%d,%d]\n",game1->player->x, game1->player->y);
	draw_rect(&(game1->img), (game1->player->y),(game1->player->x), tile_size, tile_size, 0xfff68f);
	mlx_put_image_to_window(game1->mlx_ptr, game1->win_ptr, game1->img.img, 0, 0);
}