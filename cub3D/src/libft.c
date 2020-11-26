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

int		get_next_line(int fd, char **line)
{
	int	n;

	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, NULL, 0))
		return (-1);
	n = get_buffer(fd, line);
	return (n);
}

int			get_buffer(int fd, char **line)
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