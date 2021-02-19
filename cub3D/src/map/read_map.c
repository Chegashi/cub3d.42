/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/19 16:58:17 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_cub	*ft_read_cub(char *s)
{
	t_cub	*cub;

	cub = ft_init_cub();
	cub->fd = open(s, O_RDONLY);
	while (get_next_line(cub->fd, &(cub->line)) > 0)
		if (*(cub->line))
			ft_fill(cub->line, cub);
	close(cub->fd);
	if (cub->floor_color[0] == -1 || cub->ceilling_color[0] == -1)
		get_err("Error\tmissing color\n");
	check_map(cub);
	return (cub);
}

void	ft_destroy_cub(t_cub *cub)
{
	free(cub->line);
	free(cub->floor_color);
	free(cub->ceilling_color);
	free(cub->resolution);
	free(cub->player_position);
	free(cub->textures);
	free(cub->map_str);
	free(cub->map);
	free(cub);
}

void	ft_fill(char *line, t_cub *cub)
{
	while (*line && !ft_is_amap(cub->line) && *line == ' ')
		line++;
	if (*line == 'R' && cub->resolution[0] == -1)
		ft_resolution(line + 1, cub);
	else if (*line == 'N' && line[1] == 'O' && !(cub->textures[0].define))
		ft_read_texture(line + 2, &(cub->textures[0]));
	else if (*line == 'E' && line[1] == 'A' && !(cub->textures[1].define))
		ft_read_texture(line + 2, &(cub->textures[1]));
	else if (*line == 'W' && line[1] == 'E' && !(cub->textures[2].define))
		ft_read_texture(line + 2, &(cub->textures[2]));
	else if (*line == 'S' && line[1] == 'O' && !(cub->textures[3].define))
		ft_read_texture(line + 2, &(cub->textures[3]));
	else if (*line == 'S' && !(cub->textures[4].define))
		ft_read_texture(line + 1, &(cub->textures[4]));
	else if (*line == 'F' && (cub->floor_color[0] == -1))
		ft_read_color(line + 1, &(cub->floor_color));
	else if (*line == 'C' && cub->ceilling_color[0] == -1)
		ft_read_color(line + 1, &(cub->ceilling_color));
	else if ((ft_is_amap(cub->line)) && !(cub->map))
		ft_read_map(cub);
	else
		get_err("error in cub file\tstart of a line\n");
}

int		ft_is_amap(char *str)
{
	while (*str && *str == ' ')
		str++;
	return ((*str == '1') ? 1 : 0);
}

void	ft_tomap(t_cub *cub)
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
			if (cub->map_str[k] != '\n' && cub->map_str[k])
			{
				if (ft_isin("EWNS", cub->map_str[k]))
					ft_set_player(cub->map_str[k], i, j, cub);
				else
					cub->map[i][j] = cub->map_str[k];
				k++;
			}
			else
				(cub->map)[i][j] = ' ';
	}
}
