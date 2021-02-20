/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:47:36 by abort             #+#    #+#             */
/*   Updated: 2021/02/20 18:01:32 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_color(char *line, int **tab)
{
	int i;
	int color;

	i = -1;
	while (*line && *line == ' ')
		line++;
	while (++i < 3)
	{
		if (!*line || !ft_isdigit(*line))
			get_err("error\t in color\n");
		color = ft_atoi_s(&line);
		if (color < 0 || color > 255)
			get_err("error\t in color must > 0 and  < 255\n");
		else
			(*tab)[i] = color;
		if ((i == 0 || i == 1) && *line != ',')
			get_err("Error \n the file must be seperated bey ',");
		(*line) ? line++ : 0;
	}
	while (*line && *line == ' ')
		line++;
	if (*line)
		get_err("error\tdon't add extra information in color\n");
}

void	ft_resolution(char *line, t_cub *cub)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		while (*line && *line == ' ')
			line++;
		if (*line && !ft_isdigit(*line))
			get_err("error\t in resolution\n");
		cub->resolution[i] = ft_atoi_s(&line);
	}
	while (*line && *line == ' ')
		line++;
	if (*line)
		get_err("error\tdon't add extra information in resloution\n");
}

void	ft_read_texture(char *line, t_texture *texture)
{
	int			len;
	int			i;
	char		*path;
	void		*file;

	if (*line != ' ')
		(get_err("error\nerror in texture\n"));
	while (*line && *line == ' ')
		line++;
	len = 0;
	i = 0;
	while (line[len] && line[len] != ' ')
		len++;
	path = ft_substr(line, 0, len);
	if (strcmp(path + strlen(path) - 4, ".xpm"))
		get_err("error extention texture file\n");
	if (!(file = mlx_xpm_file_to_image(g_game->mlx_ptr,
		path, &(texture->width), &(texture->hight))))
		get_err("error\tinvalide texture file\n");
	else
	{
		texture->color = (int*)mlx_get_data_addr(file, &(texture->bpp),
		&(texture->l_len), &(texture->endian));
		texture->define = 1;
	}
}

void	ft_read_map(t_cub *cub)
{
	int		gnl_return;
	int		len;
	char	*tmp;

	len = 0;
	gnl_return = 1;
	while (gnl_return)
	{
		if ((*(cub->line) == ' ' || *(cub->line) == '1'))
		{
			(cub->nbr_ligne)++;
			len = ft_strlen(cub->line);
			if (len > cub->nbr_column)
				cub->nbr_column = len;
			tmp = ft_strjoinn(cub->map_str, cub->line);
			free(cub->map_str);
			cub->map_str = tmp;
			cub->line = ft_init_str(cub->line);
		}
		else if (gnl_return && !*(cub->line))
			get_err("the map must be the last in the file\n");
		gnl_return = get_next_line(cub->fd, &(cub->line));
	}
	ft_tomap(cub);
}

void	check_map(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	if (!(cub->direction))
		get_err("error\tmissing the player direction\n");
	while (++i < cub->nbr_ligne)
	{
		j = -1;
		while (++j < cub->nbr_column)
		{
			if ((!i || !j || i == cub->nbr_ligne - 1
				|| j == cub->nbr_column - 1)
				&& (cub->map[i][j] != '1' && cub->map[i][j] != ' '))
				get_err("error\tthe map must be ontoured by 1\n");
			if ((cub->map[i][j] == '0' || cub->map[i][j] == '2')
				&& (cub->map[i][j - 1] == ' ' || cub->map[i][j + 1] == ' '
				|| cub->map[i + 1][j] == ' ' || cub->map[i - 1][j] == ' '))
				get_err("error\tyou the 0,2 entoured with 0 or 1\n");
			if (!ft_isin(" 120", cub->map[i][j]))
				get_err("error\tbad caracter in the map\n");
		}
	}
}
