#include "libft.h" 

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
}

int		ft_atoi_s(char **s)
{
	int nbr;

	nbr = 0;
	while (!ft_isdigit(**s))
		(*s)++;
	while (ft_isdigit(**s))
	{
		nbr = nbr * 10 + **s - '0';
		(*s)++;
	}
	return(nbr);
}

char	*ft_strjoinn(char *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen((char*)s1);
	s2_len = ft_strlen((char*)s2);
	if (!(res = malloc((s1_len + s2_len + 2) * sizeof(char))))
		return (NULL);
	else
	{
		while (i < s1_len)
			res[j++] = s1[i++];
		i = 0;
		(*s1) ? res[j++] = '\n' : 0;
		while (i < s2_len)
			res[j++] = s2[i++];
	}
	res[j] = '\0';
	return (res);
}

int		ft_isin(char *s, char c)
{
	while (*s)
		if (*s == c)
			return(1);
		else
			s++;
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}