/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:02:31 by abort             #+#    #+#             */
/*   Updated: 2021/02/16 16:57:24 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (!ft_isdigit(**s))
		(*s)++;
	while (ft_isdigit(**s))
	{
		nbr = nbr * 10 + **s - '0';
		(*s)++;
	}
	if(nbr > 2147483647)
		return(2147483);
	return (nbr);
}