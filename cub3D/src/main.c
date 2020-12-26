/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/26 12:47:49 by mochegri         ###   ########.fr       */
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
	// int		sizex;
    // int		sizey;
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
	ft_render_player(game);
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
	ft_draw_disque(&(game1->img), (game1->player->y) * map_coef,(game1->player->x) * map_coef, 5, 0xfff68f);
	ft_render_line(&(game1->img), (game1->player->y) * map_coef,(game1->player->x) * map_coef, game1->player->rotationAngle,0xf0f68f );
	mlx_put_image_to_window(game1->mlx_ptr, game1->win_ptr, game1->img.img, 0, 0);
}
// void	ft_prosesinput(t_game *game)
// {
// 	///f//
// }

// void	ft_update(t_game *game)
// {
// 	//e
// }

// void	ft_render(t_game *game)
// {
// 	///d
// }
// void 		ft_destroy(t_game *game)
// {
// 	///e
// }

void ft_draw_disque(t_data *data, int x, int y, int r, int color)
{
	int i;
	int j;

	i = x - r;
	while (++i < x + r)
	{
		j = y - r;
		while (++j < y + r)
		{
			if (pow(i - x, 2) + pow(j - y, 2) < pow(r, 2))
				my_mlx_pixel_put(data,i,j,color);
		}
	}
}
int abs(int n)
{
	return (n > 0 ? n : - 1 * n);
}

void	ft_render_line(t_data *data, int x, int y, double angle, int color)
{
	double top_x;
	double top_y;
	double dx;
	double dy;
	double i;
	double j;

	top_x = x + cos(angle)*100;
	top_y = y + sin(angle)*100;
	double steps;
	dx = (x - top_x);
	dy = (y - top_y);	steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

	double xinc = dx/((double)steps);
	double yinc = dy/((double)steps);
	// m = (top_y - y) / (top_x - x);
	i = x - 1;
	j = y - 1;
	int k = -1;
	// printf("x:%d ,y:%d, xx:%f yy:%f angle:%f m:%f cos(angle):%f,sin(angle):%f\n",x,y,top_x,top_y,angle,m, cos(angle),sin(angle));
	while (++k < steps)
	{
		i += xinc;
		j += yinc; 
		printf("[%f,%f]\n",i,j);
		my_mlx_pixel_put(data,i,j,color);
	}
}