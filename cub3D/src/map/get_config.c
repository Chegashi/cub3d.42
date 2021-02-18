/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:47:36 by abort             #+#    #+#             */
/*   Updated: 2021/02/18 16:03:54 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_color(char *line, int **tab)
{
	int i;
	int color;

	i = -1;
	while (++i < 3)
	{
		while (*line && (*line == ' ' || *line == ',' || *line == '+'))
			line++;
		if (*line && !ft_isdigit(*line))
			get_err("error\t in color\n");
		color = ft_atoi_s(&line);
		if (color < 0 || color > 255)
			get_err("error\t in color\n");
		else
			(*tab)[i] = color;
	}
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
}

void	ft_read_texture(char *line, t_texture *texture)
{
	int			len;
	int			i;
	char		*path;
	void		*file;

	while (*line && *line == ' ')
		line++;
	len = 0;
	i = 0;
	while (line[len] && line[len] != ' ')
		len++;
	path = ft_substr(line, 0, len);
	if (!(file = mlx_xpm_file_to_image(g_game->mlx_ptr,
		path, &(texture->width), &(texture->hight))))
		get_err("error\tinvalide texture file\n");
	else
		texture->color = (int*)mlx_get_data_addr(file, &(texture->bpp),
		&(texture->l_len), &(texture->endian));
}

void	ft_read_map(t_cub *cub)
{
	int		gnl_return;
	int		len;
	char	*tmp;

	len = 0;
	gnl_return = 1;
	while (gnl_return && ft_is_amap(cub->line))
	{
		if (*(cub->line) == ' ' || *(cub->line) == '1')
		{
			(cub->nbr_ligne)++;
			len = ft_strlen(cub->line);
			if (len > cub->nbr_column)
				cub->nbr_column = len;
			tmp = ft_strjoinn(cub->map_str, cub->line);
			free(cub->map_str);
			cub->map_str = tmp;
			cub->line = ft_init_str(cub->line);
			gnl_return = get_next_line(cub->fd, &(cub->line));
		}
		else if (!gnl_return)
			get_err("error\tthe map must tart with '1' or ' '\n");
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
			if ((cub->map[i][j] == '0' || cub->map[i][j] == 2)
				&& (cub->map[i][j - 1] == ' ' || cub->map[i][j + 1] == ' '
				|| cub->map[i + 1][j] == ' '
				|| cub->map[i - 1][j] == ' '))
				get_err("error\tyou have a file,the 0 entoured with 0 or 1\n");
		}
	}
}
