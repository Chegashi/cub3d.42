/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/07 01:15:22 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"

# define BUFFER_SIZE 64
# define TRUE 1
# define FALSE 0

typedef struct	s_column
{
	char				value;
	struct s_column		*next;
}				t_column;

typedef struct 	s_line
{
	t_column			*first;
	struct s_line		*next;
}				t_line;

typedef struct	s_map
{
	t_line		*first;
	int			nbr_ligne ;
	int			nbr_column;
}				t_map;

typedef struct		s_cub
{
	int		resolution_x;
	int		resolution_y;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*sprite_texture;
	int		*floor_color;
	int		*ceilling_color;
	t_map	*map;
	int		valide;
}					t_cub;

t_cub	*ft_read_cub(char *s);
t_cub	*ft_init_cub();
void	ft_fill(char **line, t_cub *cub);
void 	ft_resolution(char *line, t_cub *cub);
int		ft_isdigit(int c);
void	ft_read_texture(char *line, char **des);
void	ft_putstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_read_color(char *line, int **tab);
char	*ft_strchr(const char *str, int c);
void	ft_map(char *line, t_map *map);


#endif