/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abort <abort@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/26 05:37:57 by abort            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include "read_map/get_next_line/get_next_line.h"
# include "read_map/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"
# define PI 3.14159265359
# define map_coef 1
# define tile_size  20

typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bpp;
    int         l_len;
    int         endian;
}				t_data;


typedef struct s_player
{
    int x;
    int y;
    float width;
    float height;
    int turnDirection;
    int walkDirection;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
	t_data  img;
}				t_player;

typedef struct		s_cub
{
	int			fd;
	int			valide;
	int			nbr_ligne;
	int			nbr_column;
	int			*resolution;
	int			*floor_color;
	int			*ceilling_color;
	int			*player_position;
	char		*line;
	char		**map;
	char		*msg;
	char		*map_str;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_texture;
	char		direction;
	t_player	*player;
}					t_cub;

typedef struct s_game
{
	int		is_running;
	char	**map;
	void	*win_ptr;
	void	*mlx_ptr;
	t_cub	*cube;
	t_data  img;
	t_data  map_img;
	t_player *player;
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
void		ft_init_game(t_game *game);
void         my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_draw_map(t_game *game);
void    	draw_rect(t_data *data, int x, int y,int lentx, int lenty, int color);
void		ft_set_player(char direct, int x, int y, t_cub * cub);
void		ft_render_player(t_game *game1);
void		ft_prosesinput(t_game *game);
void		ft_update(t_game *game);
void		ft_render(t_game *game);
void		ft_destroy(t_game *game);
t_cub		*ft_read_cub(char *s);
t_cub		*ft_init_cub();
t_game		*ft_setup(t_game *game1, char *file);
t_player	*ft_init_player(t_cub *cub);



#endif