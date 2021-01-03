/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:21:37 by mochegri          #+#    #+#             */
/*   Updated: 2020/12/17 04:47:38 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT__LIBFT_H
# define __FT__LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

char	    *ft_strchr(const char *str, int c);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
void	    ft_putstr(char *str);
int	        ft_isdigit(int c);
int		    ft_atoi_s(char **s);
int		    get_next_line(int fd, char **line);
int		    get_buffer(int fd, char **line);
void	    ft_end(char **line, char **tmp, int end);
size_t	    ft_strlen(const char *str);
char	    *ft_char_calloc(size_t cont);
char	    *ft_strdup(const char *src);
int		    ft_the_end(char **tmp, char **line, char **end);
char    	*ft_strjoinn(char *s1, char const *s2);
int	    	ft_isin(char *s, char c);
char	*ft_strcpy(char *dest, char *src);
#endif