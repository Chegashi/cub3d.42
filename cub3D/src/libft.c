#include "libft.h" 

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*tmp;
	char	locate;

	locate = (char)c;
	tmp = (char*)str;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == locate)
			return (tmp + i);
		else
			i++;
	}
	if (tmp[i] == '\0' && locate == '\0')
		return (tmp + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_ch;
	int		i;

	i = 0;
	ptr_ch = NULL;
	if (!s)
		return (NULL);
	if (start > len)
		len = 0;
	ptr_ch = (char*)malloc(((int)len + 1) * sizeof(char));
	if (ptr_ch == NULL)
		return (0);
	else
	{
		while (s[i] != '\0' && i < (int)len)
		{
			ptr_ch[i] = s[(int)start + i];
			i++;
		}
		ptr_ch[i] = '\0';
	}
	return (ptr_ch);
}

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	i;

	i = -1;
	p = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (p == 0)
		return (0);
	while (++i < ft_strlen(src))
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char const *s2)
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
	if (!(res = malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (i < s1_len)
			res[j++] = s1[i++];
		i = 0;
		while (i < s2_len)
			res[j++] = s2[i++];
	}
	res[j] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

char	*ft_char_calloc(size_t cont)
{
	char	*str;

	str = (char*)malloc(cont);
	if (str == 0)
		return (0);
	return (str);
}

int		ft_isin(char *s, char c)
{
	while (*s)
	{if (*s == c)
		return(1);
	else
		s++;
	}
	return (0);
} 