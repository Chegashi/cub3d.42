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
	line = (char*)malloc(sizeof(char));
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
	cub->north_texture = NULL;
	cub->south_texture = NULL;
	cub->west_texture = NULL;
	cub->east_texture = NULL;
	cub->sprite_texture = NULL;
	cub->floor_color = (int*)malloc(sizeof(int) * 3);
	cub->ceilling_color = (int*)malloc(sizeof(int) * 3);
	while(++i < 3)
	{
		cub->floor_color[i] = -1;
		cub->ceilling_color[i] = -1;
	}
	cub->map = (t_map*)malloc(sizeof(t_map));
	cub->map->first = (t_line*)malloc(sizeof(t_line));
	cub->map->nbr_column = 0;
	cub->map->nbr_ligne = 0;
	return(cub);
}

void	ft_fill(char **line, t_cub *cub)

{
	if(*line[0] == 'R' && cub->resolution_x != -1)
		ft_resolution(*line, cub);
	else if(*line[0] == 'N' && cub->north_texture)
		ft_read_texture(*line, &cub->north_texture);
	else if(*line[0] == 'E' && cub->east_texture)
		ft_read_texture(*line, &cub->east_texture);
	else if(*line[0] == 'W' && cub->west_texture)
		ft_read_texture(*line, &cub->west_texture);
	else if(*line[0] == 'S' && *line[1] == 'O' && cub->south_texture)
		ft_read_texture(*line, &cub->south_texture);
	else if(*line[0] == 'S' && *line[1] == ' ' && cub->sprite_texture)
		ft_read_texture(*line, &cub->sprite_texture);
	else if(*line[0] == 'F' && cub->floor_color[0] != -1)
		ft_read_color(*line, &cub->floor_color);
	else if(*line[0] == 'C' && cub->ceilling_color[0] != -1)
		ft_read_color(*line, &cub->ceilling_color);
	else if (ft_strchr("RNFWSFC", *line[0]))
		cub->valide = 0;
	else
		ft_map(*line, &cub->map);
}
void	ft_read_color(char *line, int **tab)
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

void	ft_read_texture(char *line, char **dest)
{
	int len;
	int start;

	int i = -1;
	while(line[++i] != ' ')
		;
	start = i + 1;
	while(line[i++])
		len++;
	dest = ft_substr(line, start, ft_strlen(line));
}	
	
	


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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_ch;
	int		i;

	i = 0;
	ptr_ch = NULL;
	if (!s)
		return (NULL);
	if (start > len)
		len = 0;
	ptr_ch = (char*)malloc(((int)len + 1) * sizeof(char));
	if (ptr_ch == NULL)
		return (0);
	else
	{
		while (s[i] != '\0' && i < (int)len)
		{
			ptr_ch[i] = s[(int)start + i];
			i++;
		}
		ptr_ch[i] = '\0';
	}
	return (ptr_ch);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*tmp;
	char	locate;

	locate = (char)c;
	tmp = (char*)str;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == locate)
			return (tmp + i);
		else
			i++;
	}
	if (tmp[i] == '\0' && locate == '\0')
		return (tmp + i);
	return (NULL);
}

void ft_map(char *line, t_map *map)
{
	t_line	*line_tmp;
	t_line	*line_new;
	line_new = (t_line*)malloc(sizeof(t_line));
	line_tmp = map->first;
	while (line_tmp)
		line_tmp = line_tmp->next;
	line_tmp = line_new;
	line_new->next = NULL;
	line_new->first = read_column(line);
}

t_column *read_colomn(char *s)
{
	t_column *char_1;
	t_column *char_2;
	char_1 = (t_column*)malloc(sizeof(t_column));
	char_1->value = *s++;
	while(*s)
	{
		char_2 = (t_column*)malloc(sizeof(t_column));
		char_2->value = *s++;
		char_2 =  char_2->next;
		char_2 = NULL;
	}
	return(char_1);
}