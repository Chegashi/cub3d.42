# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abort <abort@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:18:52 by mochegri          #+#    #+#              #
#    Updated: 2020/12/26 04:59:15 by abort            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
NAME = cub3d
flags = -Wall -Wextra -Werror
SRCS = 	main.c \
		read_map/libft/ft_isdigit.c \
		read_map/libft/libft.c \
		read_map/get_next_line/get_next_line.c \
		read_map/get_next_lineget_next_line_utils.c \
		cub.c \

arg = -L/usr/X11/lib /usr/X11/lib/libmlx.a /lib/x86_64-linux-gnu/libbsd.so.0 -lXext -lX11  -lm  -I   ./Tools/Headers -I ./keys -g

all : $(NAME)
	$(C) -I  $(SRCS) -o cub3d  $(arg)

$(NAME):
	all
