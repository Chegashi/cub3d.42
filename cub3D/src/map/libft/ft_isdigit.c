/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:02:31 by abort             #+#    #+#             */
/*   Updated: 2021/02/17 18:04:29 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../cub3d.h"
#include <stdio.h>
int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
		if (s1[i] == s2[i])
			i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_atoi_s(char **s)
{
	int nbr;

	nbr = 0;		
	while (*s && **s == ' ')
		(*s)++;
	if (*s)
		if (!ft_isdigit(**s))
			get_err("error\t in resolution\n");
	while (*s && ft_isdigit(**s))
	{
		nbr = nbr * 10 + **s - '0';
		(*s)++;
	}
	return ((nbr > 2147483647) ? 2147483 : nbr);
}

void		*ft_memset(void *b, int c, size_t n)
{
	int				i;
	unsigned char	m;
	unsigned char	*str;

	i = 0;
	str = b;
	m = (unsigned char)c;
	while (i < (int)n)
	{
		*(str++) = m;
		i++;
	}
	return (b);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*tmp;

	tmp = (unsigned char*)dst;
	i = 0;
	if (dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int)n)
	{
		ft_memset(tmp, ((char*)src)[i], 1);
		i++;
		tmp++;
	}
	return (dst);
}