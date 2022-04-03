/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:00:46 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/03 20:48:49 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *c)
{
	int	i;	

	if (c == 0)
		return (0);
	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

static char	*ft_connect(char *s1, char *s2, char	*new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == 0)
		return (0);
	return (ft_connect(s1, s2, new));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned int	endind;

	sub = NULL;
	if (s == 0)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (NULL);
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	endind = start + (unsigned int)len;
	sub = (char *)malloc(len + 1);
	if (sub == 0)
		return (0);
	while (start < endind)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
