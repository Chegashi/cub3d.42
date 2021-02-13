/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/13 18:50:44 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
		ft_check_arg(ac, av);
		ft_setup(av[1]);
		mlx_key_hook(g_game->win_ptr, key_hook, g_game);
		mlx_hook(g_game->win_ptr, 2, 0, key_hook, g_game);
	//	mlx_loop_hook(g_game->mlx_ptr, key_hook, g_game);
		mlx_loop(g_game->mlx_ptr);
	//ft_destroy(1, game);
	return (0);
}

int		ft_destroy(int keycode)
{
	printf("%d\n", keycode);
	mlx_destroy_window(g_game->mlx_ptr, g_game->win_ptr);
	exit(1);
	return (0);
}

void	ft_setup(char *file)
{
	g_game = (t_game*)malloc(sizeof(t_game));
	g_game->mlx_ptr = mlx_init();
	g_game->cube = ft_read_cub(file);
	if (!g_game->cube->valide)
		ft_destroy_cub(g_game->cube);
	else
	{
		ft_fill_game();
		ft_render();
	}
}

void	ft_render(void)
{
	ft_clean_win();
	ft_raycasting();
	ft_render_celing();
	ft_render_wall();
	ft_render_floor();
	//ft_render_sprite();
	//ft_render_map();
	//ft_render_rays();
	//ft_render_player();
	mlx_put_image_to_window(g_game->mlx_ptr, g_game->win_ptr,
	g_game->img.img, 0, 0);
}

void	ft_fill_game(void)
{
	int		*resol;

	int		sizex;
	int		sizey;
	
	mlx_get_screen_size(g_game->mlx_ptr, &sizex, &sizey);
	if (g_game->cube->resolution[0] > sizex || g_game->cube->resolution[1] > sizey)
	{
		g_game->cube->resolution[0] = sizex;
		g_game->cube->resolution[1] = sizey;
	}
	resol = g_game->cube->resolution;
	g_game->win_ptr = mlx_new_window(g_game->mlx_ptr, resol[0],
	resol[1], "Cub3d");
	g_game->img.img = mlx_new_image(g_game->mlx_ptr, resol[0], resol[1]);
	g_game->player = ft_init_player(g_game->cube);
	g_game->img.addr = mlx_get_data_addr(g_game->img.img,
	&(g_game->img.bpp), &(g_game->img.l_len), &(g_game->img.endian));
	g_game->width = g_game->cube->resolution[0];
	g_game->height = g_game->cube->resolution[1];
	g_game->rays = (t_ray*)malloc(sizeof(t_ray) * (g_game->width + 1));
	g_game->plyr.x = g_game->player->x;
	g_game->plyr.y = g_game->player->y;
	ft_init_sprite();
}

void	ft_check_arg(int ac, char **av)
{
	char s[50];

	*s = 0;
	if (ac < 2 || ac > 3)
		ft_strcpy(s,"ereur dargument\n");
	else if (!ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		ft_strcpy(s,"ereur extention map file\n");
	else if (ft_strcmp(av[2], "--save"))
		ft_scren_shot();
	else
		ft_strcpy(s,"ereur dans le troisieme arg\n");
	if (!*s)
	exit(1);
}

void	ft_scren_shot(void)
{
	//todo:
}