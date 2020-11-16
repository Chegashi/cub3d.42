/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/16 18:23:20 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main(int ac, char **av)
{
	char *line = "10000000000000001101010010001";
	t_map *map = ft_initmap();
	t_line	*line_tmp;
	t_line	*line_new;
	line_tmp = map->first;
	while (line_tmp->next)
		line_tmp = line_tmp->next;
	line_new = (t_line*)malloc(sizeof(t_line));
	line_new->first = read_colomn(line);
	line_new->next = NULL;
	line_tmp->next = line_new;
	
	return 0;
}
