/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/28 08:28:29 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_cub	*ft_read_cub(char *s)
{
	t_cub	*cub;

	cub = ft_init_cub();
	cub->fd = open(s, O_RDONLY);
	while(get_next_line(cub->fd, &(cub->line)) > 0)
		ft_fill(cub->line, cub);
	check_map(cub);
	
	return(cub);
}

void	ft_fill(char *line, t_cub *cub)
{
	if(*line == '\0')
		return ;
	else if(*line == 'R' && cub->resolution[0] == -1)
		ft_resolution(line, cub);
	else if(*line == 'N' && !(cub->north_texture))
		ft_read_texture(line, &(cub->north_texture));
	else if(*line == 'E' && !(cub->east_texture))
		ft_read_texture(line, &(cub->east_texture));
	else if(*line == 'W' && !(cub->west_texture))
		ft_read_texture(line, &(cub->west_texture));
	else if(*line == 'S' && line[1] == 'O' && !(cub->south_texture))
		ft_read_texture(line, &cub->south_texture);
	else if(*line == 'S' && line[1] == ' ' && !(cub->sprite_texture))
		ft_read_texture(line, &(cub->sprite_texture));
	else if(*line == 'F' && (cub->floor_color[0] == -1))
		ft_read_color(line, &(cub->floor_color));
	else if(*line == 'C' && cub->ceilling_color[0] == -1)
		ft_read_color(line, &(cub->ceilling_color));
	else if ((*line == ' ' || *line == '1') && !(cub->map))
		ft_read_map(cub);
	else
		get_err(cub, "ereur in cub file\n start line\n");
}

void ft_tomap(t_cub *cub)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = -1;
	cub->map = (char**)malloc(sizeof(char*) * cub->nbr_ligne);
	while (++i < cub->nbr_ligne)
	{
		cub->map[i] = (char*)malloc(sizeof(char) * cub->nbr_column);
		j = -1;
		k++;
		while (++j < cub->nbr_column)
		{
			if (cub->map_str[k] != '\n' && cub->map_str[k])
			{
				if(ft_isin("EWNS",cub->map_str[k]))
					ft_set_player(cub->map_str[k], i, j, cub);
				else
					cub->map[i][j] = cub->map_str[k];
				k++;
			}
			else
				(cub->map)[i][j] = ' ';
		}
	}
}

void	ft_set_player(char direct, int x, int y, t_cub * cub)
{
	cub->direction =  direct;
	cub->map[x][y] = '0';
	cub->player_position[0] = x;
	cub->player_position[1] = y;
}