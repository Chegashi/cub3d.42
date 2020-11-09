/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/07 01:21:17 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*ft_read_cub(char *s)
{
	int		fd;
	char	*line;
	t_cub	*cub;
	char	text;

	cub = ft_init_cub();
	line = (char**)malloc(sizeof(char*));
	fd = open(s, O_RDONLY);
	while(get_next_line(fd, &line) > 0)
		ft_fill(*line, cub);
	return(cub);
}

t_cub	*ft_init_cub()
{
	int i;

	i = -1;
	t_cub	*cub;
	cub = (t_cub*)malloc(sizeof(t_cub));
	cub->resolution_x = -1;
	cub->resolution_y = -1;
	cub->north_texture = ft_strdup("");
	cub->south_texture = ft_strdup("");
	cub->west_texture = ft_strdup("");
	cub->east_texture = ft_strdup("");
	cub->sprite_texture = ft_strdup("");
	while(++i < 3)
	{
		cub->floor_color[i] = -1;
		cub->ceilling_color[i] = -1;
	}
	cub->map = (s_map*)sizeof(s_map);
	return(map);
}

void	ft_fill(char *line, t_cub *cub)

{
	if(line[0] == 'R')
		ft_resolution(line, cub);
	else if(line[0] == 'N')
		ft_read_texture(line, cub->north_texture);
	else if(line[0] == 'E')
		ft_read_texture(line, cub->east_texture);
	else if(line[0] == 'W')
		ft_read_texture(line, cub->west_testure);
	else if(line[0] == 'S' && line[1] == 'O')
		ft_read_texture(line, cub->south_texture);
	else if(line[0] == 'S' && line[1] == ' ')
		ft_read_texture(line, cub->sprite_texture)
	else if(line[0] == 'F')
		ft_read _color(line, cub->floor_color);
	else if(line[0] == 'C')
		ft_read_color(line, cub->ceilling_color);
	else
		ft_cub(line, cub);
}
void	ft_read_color(char *line, char *id, t_cub)
{
	if(id == "FLOOR")
		if(cub->floor_color[0] != -1)

}

void 	ft_resolution(char *line, t_cub *cub)

{
	if(cub->resolution_x != -1 || cub->resolution_y != -1)
	{
		ft_putstr("EREUR");
		cub->valide = FALSE;
	}
	cub->resolution_x = ft_atoi_s(line);
	cub->resolution_y = ft_atoi_s(line);
}

void	ft_read_texture(char *line, char *id, t_cub *cub)
{
	if(id = "NORTH" && cub->(north_texture) == "")
			cub->north_texture = ft_get_path(line);
	else if(id = "EAST" && cub->(*east_texture) == "")
			cub->east_texture = ft_get_path(line);
	else if(id = "WEAST" && cub->(*west_texture) == "")
			cub->west_texture = ft_getpath(line);
	else if(id = "SOUTH" && cub->(*south_texture) == "")
		cub->west_texture = ft_get_path(line);
	else if(id = "SPRITE" && cub->(*sprite_texture) == "")
		cub->sprite_texture = ft_get_path(line);
	else
		cub->valide = FALSE;
}
int	ft_atoi_s(char *s)
{
	int nbr;
	nbr = 0;
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10 + *s - '0';
		s++;
	}
	return(nbr);
}

char	*ft_getpath(char *s)
{
	int len;
	len = 0;
	char *s1;
	s1=s;
	while(s1++)
		len++;
	
}