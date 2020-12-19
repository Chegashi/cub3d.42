# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:18:52 by mochegri          #+#    #+#              #
#    Updated: 2020/12/18 02:28:17 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
NAME = cub3d
flags = -Wall -Wextra -Werror
SRCS = 	main.c
		get_next_line.c/
		get_next_line_utils.c/
all : $(NAME)
	gcc -I /usr/local/include -o cub3d main.c read_map.c get_next_line/*.c libft/libft.c cub.c -L ../mlx -lmlx -framework opengl -framework  appkit
$(NAME):
	all
