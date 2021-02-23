/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:48:30 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/22 10:57:52 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_utils(int keycode, t_player *p)
{
	p->walkdirection = 0;
	if (keycode == 13)
		p->walkdirection = 1;
	else if (keycode == 123)
		p->turndirection = -1;
	else if (keycode == 1)
		p->walkdirection = -1;
	else if (keycode == 124)
		p->turndirection = 1;
	else if (keycode == 0)
	{
		p->x += p->walkspeed * cos(p->rotationangle - PI / 2);
		p->y += p->walkspeed * sin(p->rotationangle - PI / 2);
	}
	else if (keycode == 2)
	{
		p->x -= p->walkspeed * cos(p->rotationangle - PI / 2);
		p->y -= p->walkspeed * sin(p->rotationangle - PI / 2);
	}
	else if (keycode == 53)
		ft_exit(EXIT_SUCCESS);
	else if (keycode == 126 && BONUS)
		p->z += 10;
	else if (keycode == 125 && BONUS)
		p->z -= 10;
}
