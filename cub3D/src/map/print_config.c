/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:57:11 by abort             #+#    #+#             */
/*   Updated: 2021/01/14 16:22:55 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_cub(t_cub *cub)
{
	int j;
    int i;
    
    i = -1;
    j = -1;
	printf("\n resolution [%d, %d]", cub->resolution[0], cub->resolution[1]);
    printf("\n north texture \t %s",cub->north_texture);
    printf("\n south texture \t %s",cub->south_texture);
    printf("\n west texture \t %s",cub->west_texture);
    printf("\n east texture \t %s",cub->east_texture);
    printf("\n sprit texture \t %s",cub->sprite_texture);
	printf("\n floor_color \t\t [%d, %d, %d]", cub->floor_color[0], cub->floor_color[1], cub->floor_color[2]);
	printf("\n ceilling_color \t [%d, %d, %d]", cub->ceilling_color[0], cub->ceilling_color[1], cub->ceilling_color[2]);
	printf("\n is valid %d %c", cub->valide, cub->direction);
	printf("\n line : %d, colomn : %d\n", cub->nbr_ligne , cub->nbr_column);
    printf("player: (%d,%d)\n", cub->player_position[0], cub->player_position[1]);
	printf("\n valide : %d\n\n", cub->valide);
	while (++i < cub->nbr_ligne)
	{
		j=-1;
		while (++j < cub->nbr_column)
			printf("%c",cub->map[i][j]);
		printf("\n");
	}
}