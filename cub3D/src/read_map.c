/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/04 06:37:44 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_cub3D.h"

void	*ft_read_map(char *s)
{
	int		fd;
	char	**line;
	t_map	*map;
	char text;

	map = (t_map*)malloc(sizeof(t_map);
	line = (char**)malloc(sizeof(char*));
	fd = open(s, O_RDONLY);
	while(get_next_line(fd, line) > 0)
		ft_filling(line, map);
}

void	ft_filling(char **line, t_map *map);
{
	if(line[0] == 'R')
	{
		map->resolution_x = ft_atoi(line);
		map-<resolution_y = ft_atoi(line);
	}
	else if(line[0] =
}

int main()
{
	read_map("../1.cub");
	return 0;
}
