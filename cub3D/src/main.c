/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:44:13 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/10 18:28:30 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main(int ac, char **av)
{
	print_cub(ft_read_cub(av[1]));

	return 0;
}
