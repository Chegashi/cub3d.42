/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 09:55:17 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/20 19:25:54 by mochegri         ###   ########.fr       */
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
	player->walkspeed = 2;
	player->turnspeed = 5 * (PI / 180);
	return (player);
}

int				key_hook(int keycode, t_game *game)
{
	t_player *p;

	p = game->player;
	p->turndirection = 0;
	p->walkdirection = 0;
	if (keycode == 13 || keycode == 126 || keycode == 65362)
		p->walkdirection++;
	if (keycode == 0 || keycode == 123 || keycode == 65363)
		p->turndirection--;
	if (keycode == 1 || keycode == 125 || keycode == 65364)
		p->walkdirection--;
	if (keycode == 2 || keycode == 124 || keycode == 65361)
		p->turndirection++;
	ft_update(game->player, game);
	ft_render(game);
	return (0);
}

int				mouse_hook(int button, int x, int y, t_game *game)
{
	if (button == 1)
	{
		game->player->x = x;
		game->player->y = y;
	}
	return (0);
}

void			ft_render_player(t_game *game1)
{
	t_point		p1;
	t_point		p2;

	p1.x = game1->player->x;
	p1.y = game1->player->y;
	p2.x = (p1.x + cos(game1->player->rotationangle) * 20 * (1 / COEF));
	p2.y = (p1.y + sin(game1->player->rotationangle) * 20 * (1 / COEF));
	ft_draw_disque(&(game1->img), game1->player->x * COEF,
	game1->player->y * COEF, 0xfff68f);
	p1.x *= COEF;
	p1.y *= COEF;
	p2.x *= COEF;
	p2.y *= COEF;
	ft_render_line(&(game1->img), p1, p2, 0xf00000);
}
