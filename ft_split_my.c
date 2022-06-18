/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:39:33 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/14 21:43:53 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	word_count(char const *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	count;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag)
			count++;
		if (s[i] != c)
			flag = 0;
		i++;
	}
	return (count);
}

static void	ft_clean(char **arr, size_t ind)
{
	while (ind > 0)
	{
		free(arr[ind - 1]);
		ind--;
	}
	free(arr);
}

static char	**make_arr_point(char const *s, char c)
{
	char	**arr;
	size_t	len_arr;

	len_arr = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (len_arr + 1));
	if (arr == NULL)
		return (NULL);
	arr[len_arr] = NULL;
	return (arr);
}

static char	**ft_strings(size_t	i_start, char	**arr, char const *s, char c)
{
	size_t	i_end;
	size_t	a;
	size_t	i;

	i = i_start;
	a = -1;
	while (i <= ft_strlen(s) && ft_strlen(s) != 0 && *s)
	{
		if (s[i] == c || i == ft_strlen(s))
		{
			i_end = i;
			arr[++a] = ft_substr(s, i_start, i_end - i_start);
			if (!arr[a])
			{
				ft_clean(arr, a);
				return (NULL);
			}
			while (s[i] == c && *s)
				i++;
			i_start = i;
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	i_start;
	char	**arr;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	arr = make_arr_point(s, c);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] == c && i != len && *s)
		i++;
	if (i == len)
		return (arr);
	i_start = i;
	return (ft_strings(i_start, arr, s, c));
}
