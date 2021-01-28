/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 09:55:17 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/28 14:18:52 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

t_player		*ft_init_player(t_cub *cub)
{
	t_player	*player;

	player = (t_player*)malloc(sizeof(t_player));
	player->x = (cub->player_position[1]) * TILE_SIZE + 10;
	player->y = (cub->player_position[0]) * TILE_SIZE + 10;
	if (cub->direction == 'N')
		player->rotationangle = (3 * PI) / 2;
	if (cub->direction == 'E')
		player->rotationangle = 0;
	if (cub->direction == 'S')
		player->rotationangle = PI / 2;
	if (cub->direction == 'W')
		player->rotationangle = PI;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->walkspeed = 5;
	player->turnspeed = 5 * (PI / 180);
	player->z = 0;
	return (player);
}

int				key_hook(int keycode)
{
	t_player *p;

	p = g_game->player;
	p->turndirection = 0;
	p->walkdirection = 0;
	if (keycode == 13 || keycode == 65362)
		p->walkdirection++;
	if (keycode == 0 || keycode == 123 || keycode == 65363)
		p->turndirection--;
	if (keycode == 1 || keycode == 65364)
		p->walkdirection--;
	if (keycode == 2 || keycode == 124 || keycode == 65361)
		p->turndirection++;
	if (keycode == 126)
		p->z += 20;
	if (keycode == 125)
		p->z -= 20;
	ft_update(g_game->player);
	ft_render();
	return (0);
}

int				mouse_hook(int button, int x, int y)
{
	if (button == 1)
	{
		g_game->player->x = x;
		g_game->player->y = y;
	}
	return (0);
}

void			ft_render_player()
{
	t_point		p1;
	t_point		p2;

	p1.x = g_game->player->x;
	p1.y = g_game->player->y;
	p2.x = (p1.x + cos(g_game->player->rotationangle) * 20 * (1 / COEF));
	p2.y = (p1.y + sin(g_game->player->rotationangle) * 20 * (1 / COEF));
	ft_draw_disque(&(g_game->img), g_game->player->x * COEF,
	g_game->player->y * COEF, 0xfff68f);
	p1.x *= COEF;
	p1.y *= COEF;
	p2.x *= COEF;
	p2.y *= COEF;
	ft_render_line(&(g_game->img), p1, p2, 0xf00000);
}
