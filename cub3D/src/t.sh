gcc -I /usr/local/include -o cub3d main.c read_map.c get_next_line/*.c libft/libft.c cub.c -L ../mlx -lmlx -framework opengl -framework  appkit
./cub3d ../maps/1.cub