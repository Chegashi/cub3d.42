# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:18:52 by mochegri          #+#    #+#              #
#    Updated: 2021/02/06 18:49:52 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

flags = -Wall -Wextra -Werror -g -fsanitize=address

arg = -I /usr/local/include -L mlx -lmlx -framework opengl -framework appkit -I src/mlx.h src/libmlx.dylib

SRCS = 	src/main.c \
		src/cub.c \
		src/math.c \
		src/player.c \
		src/raycasting.c \
		src/rende.c \
		src/render3d.c \
		src/sprite.c \
		src/map/get_config.c \
		src/map/init_config.c \
		src/map/print_config.c \
		src/map/read_map.c \
		src/map/libft/ft_isdigit.c \
		src/map/libft/libft.c \
		src/map/get_next_line/get_next_line.c \
		src/map/get_next_line/get_next_line_utils.c\

all : $(NAME)

$(NAME):
	# gcc $(flags) $(SRCS) $(arg) -o $(NAME)
	

clean: 
	rm -rf *.o

fclean: clean
	rm -rf *.a

re: fclean all