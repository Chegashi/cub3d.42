/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:57:11 by abort             #+#    #+#             */
/*   Updated: 2020/12/26 05:21:35 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void print_cub(t_cub *cub)
// {
// 	int j,i=-1;
// 	ft_printf("\n resolution [%d, %d]", cub->resolution[0], cub->resolution[1]);
//     ft_printf("\n north texture \t %s",cub->north_texture);
//     ft_printf("\n south texture \t %s",cub->south_texture);
//     ft_printf("\n west texture \t %s",cub->west_texture);
//     ft_printf("\n east texture \t %s",cub->east_texture);
//     ft_printf("\n sprit texture \t %s",cub->sprite_texture);
// 	ft_printf("\n floor_color \t\t [%d, %d, %d]", cub->floor_color[0], cub->floor_color[1], cub->floor_color[2]);
// 	ft_printf("\n ceilling_color \t [%d, %d, %d]", cub->ceilling_color[0], cub->ceilling_color[1], cub->ceilling_color[2]);
// 	ft_printf("\n is valid %d %c", cub->valide, cub->direction);
// 	ft_printf("\n line : %d, colomn : %d\n", cub->nbr_ligne , cub->nbr_column);
// 	ft_printf("\n map : \n%s\n\n", cub->msg);
// 	while (++i < cub->nbr_ligne)
// 	{
// 		j=-1;
// 		while (++j < cub->nbr_column)
// 			ft_printf("%c",cub->map[i][j]);
// 		ft_printf("\n");
// 	}
// }