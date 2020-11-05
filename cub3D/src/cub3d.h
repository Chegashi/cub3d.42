/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:12:27 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/05 06:27:56 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_CUB3D_H
# define __FT_CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 64

typedef struct		s_game
{
	int		resolution_x;
	int		resolution_y;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*sprite_texture;
	int		floor_color[3];
	int		ceilling_color[3];
	char	**map;
	int		runing;
	void	*mlx_ptr;
	void	*win_ptr;	
}	t_game;

int			get_next_line(int fd, char **line);
int			get_buffer(int fd, char **line);
void		ft_end(char **line, char **tmp, int end);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_char_calloc(size_t cont);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_the_end(char **tmp, char **line, char **end);
t_game		*ft_win_init(char *s);
void		ft_fill

#endif
