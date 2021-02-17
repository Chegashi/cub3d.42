/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/17 18:49:34 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	ft_check_arg(ac, av);
	ft_setup(av[1]);
	// mlx_key_hook(g_game->win_ptr, key_hook, g_game);
	// mlx_hook(g_game->win_ptr, 2, 0, key_hook, g_game);
	// mlx_hook(g_game->win_ptr, 17, 0, ft_exit, EXIT_SUCCESS);
	// mlx_loop(g_game->mlx_ptr);
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
	ft_fill_game();
	ft_render();
}

void	ft_render(void)
{
	ft_clean_win();
	//ft_raycasting();
	//ft_render_celing();
	//ft_render_wall();
	//ft_render_floor();
	// ft_render_sprite();
	//ft_render_map();
	// ft_render_rays();
	// ft_render_player();
	// ft_rendr_sp_map();
	if (g_save)
	{
		ft_scren_shot();
	}
	else
	;
	mlx_put_image_to_window(g_game->mlx_ptr, g_game->win_ptr,
	g_game->img.img, 0, 0);	
}

void		ft_rendr_sp_map(void)
{
		int			i;
	int			tilex;
	int			tiley;
	t_square	sqr;

	i = -1;
	while (++i < g_game->sprites.nbr)
	{
		tilex = g_game->sprites.sprite_tab[i].x - g_game->ts / 2;
		tiley = g_game->sprites.sprite_tab[i].y - g_game->ts / 2;
		sqr.color = (g_game->sprites.sprite_tab[i].is_visible) ? 0xffff : 0x0ff;
		sqr.x = tilex * COEF;
		sqr.y = tiley * COEF;
		sqr.lent = g_game->ts * COEF;
		draw_rect(&(g_game->img), sqr);
	}
}

void	ft_fill_game(void)
{
	int		*resol;

	ft_get_tilesize();
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
	if (ac < 2 || ac > 3)
		get_err("error \tdargument\n");
	else if (strcmp(av[1] + strlen(av[1]) - 4, ".cub"))
		get_err("error extention map file\n");
	else if (ac == 3 && !ft_strcmp(av[2], "--save"))
		g_save = 1;
	else
		g_save = 0;
}

void	ft_scren_shot()
{
	ft_save();
	ft_exit(EXIT_SUCCESS);
}

void	ft_get_tilesize(void)
{
	int res;
	int	rows;
	int		sizex;
	int		sizey;

	mlx_get_screen_size(g_game->mlx_ptr, &sizex, &sizey);
	if (g_game->cube->resolution[0] > sizex
	|| g_game->cube->resolution[1] > sizey)
	{
		g_game->cube->resolution[0] = sizex;
		g_game->cube->resolution[1] = sizey;
	}
	if (g_game->cube->resolution[0] < 500
	|| g_game->cube->resolution[1] < 355)
	{
		g_game->cube->resolution[0] = 500;
		g_game->cube->resolution[1] = 355;
	}
	res = (g_game->width < g_game->height) ? g_game->width : g_game->height;
	rows = (g_game->cube->nbr_column > g_game->cube->nbr_ligne)
	? g_game->cube->nbr_column : g_game->cube->nbr_ligne;
	g_game->ts = res / rows;
	
}