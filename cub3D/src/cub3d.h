/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/07 16:36:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include "map/get_next_line/get_next_line.h"
# include "map/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# define PI 3.14159265359
# define COEF 1
# define TILE_SIZE  20
# define FOV_H deg_to_rad(60)
# define FOV_V deg_to_rad(60)
# define UP 1
# define RIGHT 2
# define DOWN 4
# define LEFT 8
# define HIT_HORIS 16
# define HIT_VERTI 32
# define INT_MAX 2147483647

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
}				t_data;

typedef struct	s_player
{
	double		x;
	double		y;
	double		z;
	double		turndirection;
	int			walkdirection;
	double		rotationangle;
	double		walkspeed;
	double		turnspeed;
}				t_player;

typedef struct s_texture
{
	int			is_defined;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
	int			*color;
	int			width;
	int			hight;
}				t_texture;

typedef struct	s_line
{
	int			color;
	double		x;
	double		y;
	double		dx;
	double		dy;
}				t_line;

typedef struct	s_square
{
	int			x;
	int			y;
	int			lent;
	int			color;
}				t_square;

typedef struct	s_rectangle
{
	double		x;
	double		y;
	double		lent_x;
	double		lent_y;
	int			color;
}				t_rectangle;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef	struct	s_ray
{
	int			is_facing;
	int			data;
	double		angl;
	double		dist;
	double		wall_start;
	double		wall_h;
	t_point		end;
}				t_ray;

typedef struct	s_cub
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
	char		*map_str;
	t_texture	*textures;
	char		direction;
	t_player	*player;
}				t_cub;

typedef struct	s_sprite
{
	int		x;
	int		y;
	int		index;
	double	distance;
	double	angle;
	double	hight;
	double	widht;
}				t_sprite;

typedef	struct	s_sprites
{
	int			nbr;
	t_sprite	*sprite_tab;
	int			*order;
	double		*z_buffer;
	// t_sprite	*distance;
	// t_texture	texture;
}				t_sprites;

typedef struct	s_game
{
	int			width;
	int			height;
	void		*win_ptr;
	void		*mlx_ptr;
	char		*msg;
	t_cub		*cube;
	t_data		img;
	t_player	*player;
	t_ray		*rays;
	t_point		plyr;
	t_sprites	sprites;
}				t_game;

int				ft_destroy(int keycode);
int				key_hook(int keycode);
int				*ft_calloc_tab_int(int n);
int				mouse_hook(int button, int x, int y);
int				ft_is_wall(double x, double y);
int				ft_is_in_map(t_point p);
int				ft_update(t_player *p);
int				ft_antoured_bywall(double x, double y);
int				ft_create_trgb(int t, int r, int g, int b);
char			*ft_init_str(char *strmem);
void			ft_fill(char *line, t_cub *cub);
void			ft_resolution(char *line, t_cub *cub);
void			ft_read_texture(char *line, t_texture *texture);
void			ft_read_color(char *line, int **tab);
void			ft_map(t_cub *cub);
void			print_cub(t_cub *cub);
void			ft_read_map(t_cub *cub);
void			ft_tomap(t_cub *cub);
void			check_map(t_cub *cub);
void			get_err(t_cub *cub, char *msg);
void			ft_init_game(t_game *game);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_render_map();
void			draw_rect(t_data *data, t_square s);
void			ft_set_player(char direct, int x, int y, t_cub *cub);
void			ft_render_player();
void			ft_render();
void			ft_draw_disque(t_data *data, int x, int y, int color);
void			ft_render_player();
void			ft_render_line(t_data *data, t_point p1, t_point p2, int color);
void			ft_render_rays();
t_point			ft_horis_interst(t_ray *ray);
t_point			ft_verti_intersect(t_ray *ray);
void			ft_cast_ray(t_ray *ray);
void			ft_raycasting();
void			ft_normilised(double *angle);
void			ft_destroy_cub(t_cub *cub);
void    		ft_render_wall();
void			ft_render_g_rect(t_data *data, t_rectangle rect);
void			ft_clean_win();
double			ft_dis_2point(t_point p1, t_point p2);
double			ft_min(double x1, double x2);
double			ft_max(double x1, double x2);
t_cub			*ft_read_cub(char *s);
t_cub			*ft_init_cub();
void			ft_setup(char *file);
t_player		*ft_init_player(t_cub *cub);
t_point			ft_translate_point(t_point p, double x, double y);
void		    ft_render_celing();
void    		ft_render_floor();
double			rad_to_deg(double x1);
double			deg_to_rad(double x1);
void			ft_fill_game(void);
void			ft_wall_texture(t_ray ray, int i);
int				ft_isasprite(double x, double y);
void			ft_init_sprite(void);
void			ft_counters_sprites(void);
void			ft_calculate_sprite(void);
void			ft_sprite_distance(void);
void			ft_sort_sprites(void);
void			ft_fill_z_buffer(void);
void			ft_highsprites(void);
t_game			*g_game;
#endif
