/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 09:55:17 by mochegri          #+#    #+#             */
/*   Updated: 2021/01/05 15:25:59 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

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
	player->walkDirection = 0;
	player->walkSpeed = 5;
	player->turnSpeed = 10 * (PI / 180);
	return (player);
}

int	        key_hook(int keycode, t_game *game)
{
	t_player *p;

	p = game->player;
	p->turnDirection = 0;
	p->walkDirection = 0;
	if (keycode == 13 || keycode == 126)
		p->walkDirection++;
	if (keycode == 0 || keycode == 123)
		p->turnDirection++;
	if (keycode == 1 || keycode == 125)
		p->walkDirection--;
	if (keycode == 2 || keycode == 124)
		p->turnDirection--;
	ft_update(game->player, game);
	ft_render(game);
	return 0;
}

int         mouse_hook(int button, int x,int y, t_game *game)
{
	if(button == 1)
	{
		game->player->x = x;
		game->player->y = y;
	}
	return 0;
}

void	    ft_render_player(t_game *game1)
{
    t_point p1;
    t_point p2;

    p1.x = game1->player->x;
    p1.y = game1->player->y;
    p2.x = p1.x + cos(game1->player->rotationAngle) * 40;
    p2.y = p1.y + sin(game1->player->rotationAngle) * 40;
	ft_draw_disque(&(game1->img), game1->player->y * map_coef,
	game1->player->x * map_coef, 5, 0xfff68f);
	ft_render_line(&(game1->img), p1,p2, 0xf0f68f);
}