/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:37:16 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/15 18:39:20 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int	n;

	free(*line);
	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, NULL, 0))
		return (-1);
	n = get_buffer(fd, line);
	if(**line != 0 && !n)
		return(1);
	return n;
}

int		get_buffer(int fd, char **line)
{
	int			n;
	static char	*tmp = NULL;
	char		*buffer;
	char		*joker;
	char		*end;

	if (tmp == NULL)
		tmp = ft_char_calloc(1);
	buffer = ft_char_calloc(BUFFER_SIZE + 1);
	while (!(end = ft_strchr(tmp, '\n')) &&
	(n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		joker = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = joker;
		end = ft_strchr(buffer, '\n');
	}
	end = ft_strchr(tmp, '\n');
	free(buffer);
	return (n = ft_the_end(&tmp, line, &end));
}

int		ft_the_end(char **tmp, char **line, char **end)
{
	char		*joker;

	if (*end != NULL)
	{
		*line = ft_substr(*tmp, 0, (*end - *tmp));
		joker = ft_strdup(*end + 1);
		free(*tmp);
		*tmp = joker;
		return (1);
	}
	else
	{
		*line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		return (0);
	}
}