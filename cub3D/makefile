# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:18:52 by mochegri          #+#    #+#              #
#    Updated: 2020/12/13 19:03:24 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
NAME = cub3d
flags = -Wall -Wextra -Werror
SRCS = 	main.c
		get_next_line.c/
		get_next_line_utils.c/
all : $(NAME)
	cc  -I /usr/local/include   src/main.c -L src/mlx  -lmlx -framework opengl -framework appkit
$(NAME):
	all
