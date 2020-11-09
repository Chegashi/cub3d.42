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

typedef struct		s_cub
{
	int		resolution_x;
	int		resolution_y;
	char	*north_texture;
	char	*south_texture;
	char	*west_testure;
	char	*east_texture;
	char	*sprite_texture;
	int		floor_color[3];
	int		ceilling_color[3];
	char	**map;
	int		valide;
}					t_cub;

typedef struct	s_column
{
	char				value;
	struct s_column		*next;
}				t_column;

typdef struct 	s_line
{
	t_column			line;
	struct s_line		*next;
}				t_line;

typedef struct	s_map
{
	t_line		*first;
	int			nbr_ligne ;
	int			nbr_column;
}				t_map;

#endif