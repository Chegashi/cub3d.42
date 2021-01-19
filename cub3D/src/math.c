/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:25:25 by abort             #+#    #+#             */
/*   Updated: 2021/01/19 12:22:12 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

float	ft_dis_2point(t_point p1, t_point p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)
				* (p1.y - p2.y)));
}

float	ft_min(float x1, float x2)
{
	return (x1 < x2) ? x1 : x2;
}

void	ft_normilised(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	*angle = (float)fmod(*angle, 2 * PI);
}

float	ft_max(float x1, float x2)
{
	return ((x1 > x2) ? x1 : x2);
}
