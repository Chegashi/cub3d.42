/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/17 13:52:56 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"
# include <string.h>

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

void		ft_fill( char *line, t_cub *cub);
void 		ft_resolution( char *line, t_cub *cub);
void		ft_read_texture( char *line, char **des);
void		ft_read_color( char *line, int **tab);
void		ft_map( char *line, t_map *map);
t_cub		*ft_read_cub(char *s);
t_cub		*ft_init_cub();
t_column    *read_colomn( char *s);
void		print_cub(t_cub *cub);
t_map *ft_initmap();

#endif