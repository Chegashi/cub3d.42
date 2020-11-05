/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/05 06:27:52 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_cub3D.h"

t_game	*ft_win_init(char *s)
{
	int		fd;
	char	**line;
	t_game	*game;
	char	text;

	game = init_game();
	line = (char**)malloc(sizeof(char*));
	fd = open(s, O_RDONLY);
	while(get_next_line(fd, line) > 0)
		ft_fill(line[0], line, game);
	if(!(game->mlx_ptr = mlx_init()))
		game->runing = false;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->resolution_x, game_resolution_y, "cub3D");
	if(!(game->win_ptr))
		game->runing = false;
	mlx_loop();
	return(game);
}

void	ft_fill(char c, char *line, t_map *game);
{
	if(line[0] == 'R')
		ft_resolution(line, game);
	else if(line[0] == 'N')
		ft_north_texture(line, game);
	else if(line[0] == 'E')
		ft_east_texture(line, game);
	else if(line[0] == 'W')
		ft_west_texture(line, game);
	else if(line[0] == 'S' && line[1] == '0')
		ft_south_texture(line, game);
	else if(line[0] == 'S' && line[1] == ' ')
		ft_sprit_texture(line, game)
	else if(line[0] == 'F')
		ft_floor_color(line, game);
	else if(line[0] == 'C')
		ft_ceilling_color(line, game);
	else
		ft_map(line, game);
}

int main()
{
	read_map("../1.cub");
	return 0;
}
