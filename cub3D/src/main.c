/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/22 19:40:09 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_cub	*cub;
	char	text;

	cub = ft_init_cub();
	line = (char*)malloc(sizeof(char));
	fd = open("1.cub", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
		printf("%s\n", line);
 	return 0;
}