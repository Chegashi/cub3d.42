/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/20 07:43:35 by abort            ###   ########.fr       */
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
# include "mlx.h"

typedef struct		s_cub
{
	int		fd;
	int		valide;
	int		nbr_ligne;
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
	char	*msg;
	char	direction;
}					t_cub;


typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bpp;
    int         l_len;
    int         endian;
}				t_data;

typedef struct s_game
{
	t_cub	*cube;
	char	**map;
	void	*win_ptr;
	void	*mlx_ptr;
	t_data  img;
	int		is_running;
}				t_game;
              

int			*ft_calloc_tab_int(int n);
char		*ft_init_str(char *strmem);
void		ft_fill( char *line, t_cub *cub);
void 		ft_resolution( char *line, t_cub *cub);
void		ft_read_texture( char *line, char **des);
void		ft_read_color( char *line, int **tab);
void		ft_map(t_cub *cub);
void		print_cub(t_cub *cub);
void		ft_read_map(t_cub *cub);
void		ft_tomap(t_cub *cub);
void		check_map(t_cub *cub);
void		get_err(t_cub *cub, char * msg);
t_cub		*ft_read_cub(char *s);
t_cub		*ft_init_cub();
void		ft_init_game(t_game *game);

#endif