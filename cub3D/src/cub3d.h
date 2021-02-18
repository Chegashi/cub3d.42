/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/18 18:53:44 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include "map/get_next_line/get_next_line.h"
# include "map/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# define PI 3.14159265359
# define UP 1
# define FOV 1.0472
# define COEF 1
# define RIGHT 2
# define DOWN 4
# define LEFT 8
# define HIT_HORIS 16
# define HIT_VERTI 32
# define INT_MAX 2147483647

typedef struct		s_data
{
	int				bpp;
	int				l_len;
	int				endian;
	char			*addr;
	void			*img;
}					t_data;

typedef struct		s_player
{
	int				walkdirection;
	double			x;
	double			y;
	double			z;
	double			turndirection;
	double			rotationangle;
	double			walkspeed;
	double			turnspeed;
}					t_player;

typedef struct		s_texture
{
	int				define;
	int				bpp;
	int				l_len;
	int				endian;
	int				*color;
	int				width;
	int				hight;
	char			*addr;
}					t_texture;

typedef struct		s_line
{
	int				color;
	double			x;
	double			y;
	double			dx;
	double			dy;
}					t_line;

typedef struct		s_square
{
	double			x;
	double			y;
	double			lent;
	double			color;
}					t_square;

typedef struct		s_rectangle
{
	int				color;
	double			x;
	double			y;
	double			lent_x;
	double			lent_y;
}					t_rectangle;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef	struct		s_ray
{
	int				is_facing;
	int				data;
	double			angl;
	double			dist;
	double			wall_h;
	double			top_pixel;
	double			bottom_pixel;
	t_point			end;
}					t_ray;

typedef struct		s_cub
{
	int				fd;
	int				valide;
	int				nbr_ligne;
	int				nbr_column;
	int				*resolution;
	int				*floor_color;
	int				*ceilling_color;
	int				*player_position;
	char			*line;
	char			**map;
	char			*map_str;
	char			direction;
	t_texture		*textures;
	t_player		*player;
}					t_cub;

typedef struct		s_sprite
{
	int				is_visible;
	double			x;
	double			y;
	double			dist;
	double			angle;
	double			size;
	double			top_y;
	double			bottom_y;
	double			scren_pos;
	double			right_x;
	double			leeft_x;
	double			x_offset;
	double			y_offset;
}					t_sprite;

typedef	struct		s_sprites
{
	int				nbr;
	t_sprite		*tab;
}					t_sprites;

typedef struct		s_bitmap
{
	int				w;
	int				he;
	int				bc;
	int				wb;
	int				imgs;
	int				bs;
	int				bob;
	int				fs;
	int				bp;
	unsigned char	h[54];
	unsigned char	* buf;
	int				ro;
	int				co;
	int				*color;
	int				fd;
}					t_bitmap;

typedef struct		s_game
{
	int				width;
	int				height;
	void			*win_ptr;
	void			*mlx_ptr;
	double			dis_plan;
	t_cub			*cube;
	t_data			img;
	t_player		*player;
	t_ray			*rays;
	t_point			plyr;
	t_sprites		sprites;
	t_bitmap		bitm;
	int				ts;
}					t_game;

int					ft_destroy(int keycode);
int					key_hook(int keycode);
int					*ft_calloc_tab_int(int n);
int					mouse_hook(int button, int x, int y);
int					ft_is_wall(double x, double y);
int					ft_is_in_map(t_point p);
int					ft_update(t_player *p);
int					ft_antoured_bywall(double x, double y);
int					ft_create_trgb(int t, int r, int g, int b);
int					ft_exit(int i);
int					ft_save(void);
int					ft_isasprite(double x, double y);
int					ft_is_amap(char *str);
char				*ft_init_str(char *strmem);
void				ft_fill(char *line, t_cub *cub);
void				ft_resolution(char *line, t_cub *cub);
void				ft_read_texture(char *line, t_texture *texture);
void				ft_read_color(char *line, int **tab);
void				ft_map(t_cub *cub);
void				ft_read_map(t_cub *cub);
void				ft_tomap(t_cub *cub);
void				check_map(t_cub *cub);
void				get_err(char *msg);
void				ft_init_game(t_game *game);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_render_map();
void				draw_rect(t_data *data, t_square s);
void				ft_set_player(char direct, int x, int y, t_cub *cub);
void				ft_render_player();
void				ft_render();
void				ft_draw_disque(t_data *data, int x, int y, int color);
void				ft_render_player();
void				ft_render_line(t_data *data,
									t_point p1, t_point p2, int color);
void				ft_render_rays();
void				ft_check_arg(int ac, char **av);
void				ft_cast_ray(t_ray *ray);
void				ft_raycasting();
void				ft_normilised(double *angle);
void				ft_destroy_cub(t_cub *cub);
void				ft_render_wall();
void				ft_render_g_rect(t_data *data, t_rectangle rect);
void				ft_clean_win();
void				ft_setup(char *file);
void				ft_render_celing();
void				ft_render_floor();
void				ft_header(void);
void				ft_save_file(void);
void				ft_initialize_save(void);
void				ft_get_tilesize(void);
void				ft_sprite_config(t_sprite *sprite);
void				ft_put_pixel_sprit(t_sprite sprite,
										t_texture texture, int i, int j);
void				ft_fill_game(void);
void				ft_3dgenerate(t_ray *ray);
void				ft_wall_texture(t_ray ray, int i);
void				ft_init_sprite(void);
void				ft_counters_sprites(void);
void				ft_sprite_calcul(void);
void				ft_sprite_dist(void);
void				ft_sort_sprites(void);
void				ft_fill_z_buffer(void);
void				ft_highsprites(void);
void				ft_render_sprite(void);
void				ft_scren_shot();
void				ft_draw_sprites(t_sprite *sprite);
void				ft_rendr_sp_map(void);
double				ft_dst_2pnt(t_point p1, t_point p2);
double				ft_min(double x1, double x2);
double				ft_max(double x1, double x2);
double				rad_to_deg(double x1);
double				deg_to_rad(double x1);
double				ft_sprite_angl(double y, double x);
t_cub				*ft_read_cub(char *s);
t_cub				*ft_init_cub();
t_point				ft_translate_point(t_point p, double x, double y);
t_point				ft_horis_interst(t_ray *ray);
t_point				ft_verti_intersect(t_ray *ray);
t_player			*ft_init_player(t_cub *cub);
t_game				*g_game;
int					g_save;
#endif
