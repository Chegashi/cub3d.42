# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:18:52 by mochegri          #+#    #+#              #
#    Updated: 2021/02/20 12:13:42 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

flags = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = 	src/main.c \
		src/cub.c \
		src/math.c \
		src/player.c \
		src/raycasting.c \
		src/rende.c \
		src/render3d.c \
		src/sprite.c \
		src/save.c \
		src/update.c \
		src/bonus.c \
		src/math_utils.c \
		src/sprite_utils.c \
		src/map/get_config.c \
		src/map/init_config.c \
		src/map/read_map.c \
		src/map/libft/ft_isdigit.c \
		src/map/libft/libft.c \
		src/map/get_next_line/get_next_line.c \
		src/map/get_next_line/get_next_line_utils.c \
		
MAND = $(SRC)

$(NAME):
	@gcc $(flags) -c $(SRCS) -D BONUS=0
	@ar -rc cub.a *.o
	@ranlib cub.a 
	@gcc $(flags) -I /usr/local/include cub.a -L /usr/local/lib/ \
	-lmlx -framework OpenGL -framework AppKit src/libmlx.dylib -o cub3D
	@rm *.o
	@rm cub.a

$(NAME_b):
	gcc $(flags) -c $(SRCS) -D BONUS=1
	@ar -rc cub.a *.o
	@ranlib cub.a 
	@gcc $(flags) -I /usr/local/include cub.a -L /usr/local/lib/ \
	-lmlx -framework OpenGL -framework AppKit src/libmlx.dylib -o cub3D
	@rm *.o
	@rm cub.a

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) cub3D

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

run: re
	./cub3d maps/1.cub
save : re
	./cub3D maps/1.cub --save

bonus : clean
	@gcc $(flags) -c $(SRCS) -D BONUS=1
	@ar -rc cub.a *.o
	@ranlib cub.a 
	@gcc $(flags) -I /usr/local/include cub.a -L /usr/local/lib/ \
	-lmlx -framework OpenGL -framework AppKit src/libmlx.dylib -o cub3D
	@rm *.o
	@rm cub.a
	./cub3D maps/1.cub 
