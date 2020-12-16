/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/16 06:09:30 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_cub
{
	int		fd;
	int		valide;
	int		nbr_ligne ;
	int		nbr_column;
	int		*resolution;
	int		*floor_color;
	int		*ceilling_color;
	char	*line;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*sprite_texture;
	char	**map;
	char	*map_str;
	
}					t_cub;

typedef struct s_game
{
	t_cub	*cube;
	char	**map;
}				t_game;

void		ft_fill( char *line, t_cub *cub);
void 		ft_resolution( char *line, t_cub *cub);
void		ft_read_texture( char *line, char **des);
void		ft_read_color( char *line, int **tab);
void		ft_map(t_cub *cub);
void		print_cub(t_cub *cub);
void		ft_read_map(t_cub *cub);
t_cub		*ft_read_cub(char *s);
t_cub		*ft_init_cub();
int			*ft_calloc_tab_int(int n);
void		ft_tomap(t_cub *cub);
char		*ft_init_str(char *strmem);

#endif