/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:35 by mochegri          #+#    #+#             */
/*   Updated: 2020/11/07 01:21:17 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

t_game	*ft_win_init(char *s)
{
	int		fd;
	char	**line;
	t_game	*game;
	char	text;

	game = ft_init_game();
	line = (char**)malloc(sizeof(char*));
	fd = open(s, O_RDONLY);
	while(get_next_line(fd, line) > 0)
		ft_fill(*line, game);
	game->mlx_ptr = mlx_init();
	if(!game->mlx_ptr)
		game->running = FALSE;
	game->win_ptr = mlx_new_window(game->mlx_ptr ,game->resolution_x, game->resolution_y, "cub3D");
	if(!(game->win_ptr))
		game->running = FALSE;
	return(game);
}

t_game	*ft_init_game()
{
	int i;

	i = 0;
	t_game	*game;
	game = (t_game*)malloc(sizeof(t_game));
	game->resolution_x = -1;
	game->resolution_y = -1;
	game->north_texture = ft_strdup("");
	game->south_texture = ft_strdup("");
	game->east_texture = ft_strdup("");
	game->sprite_texture = ft_strdup("");
	while(i++ < 3)
	{
		game->floor_color[i] = -1;
		game->ceilling_color[i] = -1;
	}
	game->map = NULL;
	game->running = TRUE;
	game->mlx_ptr = NULL;
	game->win_ptr = 0;
	return(game);
}

void	ft_fill(char *line, t_game *game)

{
	if(line[0] == 'R')
		ft_resolution(line, game);
	else if(line[0] == 'N')
		ft_read_texture(line, "NORTH", game);
	else if(line[0] == 'E')
		ft_read_texture(line, "EAST", game);
	else if(line[0] == 'W')
		ft_read_texture(line, "WEAST", game);
	else if(line[0] == 'S' && line[1] == 'O')
		ft_read_texture(line, "SOUTH",  game);
	else if(line[0] == 'S' && line[1] == ' ')
		ft_read_texture(line, "SPRITE ", game)
	else if(line[0] == 'F')
		ft_read _color(line, "FLOOR", game);
	else if(line[0] == 'C')
		ft_read_color(line, "CEILLING", game);
	else
		ft_map(line, game);
}
void	ft_read_color(char *line, char *id, t_game)
{
	if(id == "FLOOR")
		if(game->floor_color[0] != -1)

}

void 	ft_resolution(char *line, t_game *game)

{
	if(game->resolution_x != -1 || game->resolution_y != -1)
	{
		ft_putstr("EREUR");
		game->running = FALSE;
	}
	game->resolution_x = ft_atoi(line);
	game->resolution_y = ft_atoi(line);
}

void	ft_read_texture(char *line, char *id, t_game *game)
{
	if(id = "NORTH" && game->(*north_texture) == "")
			game->north_texture = ft_get_path(line);
	else if(id = "EAST" && game->(*east_texture) == "")
			game->east_texture = ft_get_path(line);
	else if(id = "WEAST" && game->(*west_texture) == "")
			game->west_texture = ft_getpath(line);
	else if(id = "SOUTH" && game->(*south_texture) == "")
		game->west_texture = ft_get_path(line);
	else if(id = "SPRITE" && game->(*sprite_texture) == "")
		game->sprite_texture = ft_get_path(line);
	else
		game->running = FALSE;
}


