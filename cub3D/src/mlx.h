/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:56:26 by mochegri          #+#    #+#             */
/*   Updated: 2021/02/20 15:39:36 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H

# define MLX_H
# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

void			*mlx_init();
void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);
int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixl_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color);
void			*mlx_new_image(void *mlx_ptr, int width, int hight);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixl,
					int *size_line, int *endian);
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
					void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),
					void *param);
int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);
int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color, char *string);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
					int *width, int *hight);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
					int *width, int *hight);
void			*mlx_png_file_to_image(void *mlx_ptr, char *file,
					int *width, int *hight);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int				mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);
int				mlx_mouse_hide();
int				mlx_mouse_show();
int				mlx_mouse_move(void *win_ptr, int x, int y);
int				mlx_mouse_get_pos(void *win_ptr, int *x, int *y);
int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);

int				mlx_sync(int cmd, void *param);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
#endif
