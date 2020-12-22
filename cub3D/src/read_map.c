/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/22 14:06:34 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_cub	*ft_init_cub()
{
	int		i;
	t_cub	*cub;

	i = -1;
	cub = (t_cub*)malloc(sizeof(t_cub));
	cub->line = (char*)malloc(sizeof(char));
	cub->floor_color = ft_calloc_tab_int(2);
	cub->ceilling_color = ft_calloc_tab_int(3);
	cub->resolution = ft_calloc_tab_int(3);
	cub->resolution[0] = -1;
	cub->resolution[1] = -1;
	cub->north_texture =  NULL;
	cub->south_texture = NULL;
	cub->west_texture = NULL;
	cub->east_texture = NULL;
	cub->sprite_texture = NULL;
	while(++i < 3)
	{
		cub->floor_color[i] = -1;
		cub->ceilling_color[i] = -1;
	}
	cub->valide = 1;
	cub->fd = -1;
	ft_map(cub);
	return(cub);
}

void	ft_map(t_cub *cub)
{
	cub->nbr_ligne = 0;
	cub->nbr_column = 0;
	cub->map_str = (char*)malloc(sizeof(char));
	cub->map_str[0] = '\0';
	cub->map = NULL;
	cub->direction = 0;
	cub->msg = (char*)malloc(sizeof(char) * 25);
	cub->msg = ft_strcpy(cub->msg, "ok");
}

int		*ft_calloc_tab_int(int n)
{
	int *tab;

	tab = (int*)malloc(sizeof(int) * n);
	if(!tab)
		return(NULL);
	return(tab);
	
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
		get_err(cub, "ereur in cub file\n");
}

void	ft_read_color(char *line, int **tab)
{
	(*tab)[0] = ft_atoi_s(&line);
	(*tab)[1] = ft_atoi_s(&line);
	(*tab)[2] = ft_atoi_s(&line);	
}

void 	ft_resolution(char *line, t_cub *cub)
{
	cub->resolution[0] = ft_atoi_s(&line);
	cub->resolution[1] = ft_atoi_s(&line);
}

void	ft_read_texture( char *line, char **dest)
{
	int len;
	int start;
	int i;
	len = 0;
	i = -1;
	while(line[++i] != ' ')
		;
	start = i + 1;
	while(line[i++])
		len++;
	*dest = ft_substr(line, start, ft_strlen(line));
}	

void ft_read_map(t_cub *cub)
{
	int		gnl_return;
	int		len;
	char	*tmp;

	len = 0;
	gnl_return = 1;
	while(gnl_return && cub->valide)
	{
		if(*(cub->line) == ' ' || *(cub->line) == '1')
		{
			(cub->nbr_ligne)++;
			len = ft_strlen(cub->line);
			if(len > cub->nbr_column)
				cub->nbr_column= len;
			tmp = ft_strjoinn(cub->map_str, cub->line);
			free(cub->map_str);
			cub->map_str = tmp;
			cub->line = ft_init_str(cub->line);
			gnl_return =  get_next_line(cub->fd, &(cub->line));
		}
		else if (!gnl_return)
			get_err(cub, "debut map erreur \n");
	}
	ft_tomap(cub);
}

char	*ft_init_str(char *str_mem)
{
	free(str_mem);
	return(ft_strdup(""));
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
				cub->map[i][j] = cub->map_str[k];
				k++;
			}
			else
				(cub->map)[i][j] = ' ';
		}
	}
}

void print_cub(t_cub *cub)
{
	int j,i=-1;
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
	printf("\n map : \n%s\n\n", cub->msg);
	while (++i < cub->nbr_ligne)
	{
		j=-1;
		while (++j < cub->nbr_column)
			printf("%c",cub->map[i][j]);
		printf("\n");
	}
}

void check_map(t_cub *cub)
{
	int i;
	int j;
	char *drct;

	drct = &(cub->direction);
	i = -1;
	while (++i < cub->nbr_ligne && cub->valide)
	{
		j=-1;
		while (++j < cub->nbr_column && cub->valide)
		{
			if (((i == 0 || j == 0|| i == (cub->nbr_ligne - 1)
			|| j == (cub->nbr_column - 1)) && (cub->map[i][j] != '1'
			&& cub->map[i][j] != ' ')) && (ft_isin("0NSWE2", cub->map[i][j])
			&& (cub->map[i - 1][j -1] == ' ' && cub->map[i - 1][j + 1] == ' '
			&& cub->map[i + 1][j + 1] == ' '
			&& cub->map[i + 1][j - 1] == ' ')))
				get_err(cub, "ereur in cub map\n");
			if (ft_isin("NSWE", cub->map[i][j]))
				*drct ? cub->valide = 0 : (*drct = cub->map[i][j]);				
		}
	}
	if (!(cub->direction))
		cub->valide = 0;	
}

void	get_err(t_cub *cub, char * msg)
{
	cub->msg = ft_strcpy(cub->msg, msg);
	cub->valide = 0;
	exit(1);
}
