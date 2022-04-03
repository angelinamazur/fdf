/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:18:30 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/03 20:48:57 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*s;
	char		*dub;
	size_t		i;

	i = 0;
	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	s = malloc(count * size);
	if (s == 0)
		return (0);
	dub = s;
	while (i < (count * size))
	{
		dub[i] = '\0';
		i++;
	}
	return ((void *)s);
}

int	ft_ind_n(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line(char **remain)
{
	int			ind_n;
	char		*line;
	char		*tmp;

	ind_n = ft_ind_n(*remain);
	line = ft_substr(*remain, 0, ind_n + 1);
	tmp = *remain;
	*remain = ft_substr(*remain, ind_n + 1, ft_strlen(*remain) - ind_n);
	free(tmp);
	return (line);
}

int	find_remain(char **remain, int fd)
{
	char		*buf;
	int			read_bytes;
	char		*tmp;

	read_bytes = 1;
	while (read_bytes > 0 && ft_ind_n(*remain) == -1)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (0);
		buf[BUFFER_SIZE] = '\0';
		read_bytes = read(fd, buf, BUFFER_SIZE);
		tmp = *remain;
		*remain = ft_strjoin(*remain, buf);
		free(tmp);
		free(buf);
	}
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			read_bytes;
	static char	*remain;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (remain == NULL)
		remain = ft_strdup("");
	read_bytes = find_remain(&remain, fd);
	if (ft_ind_n(remain) != -1)
		return (ft_line(&remain));
	if (remain && read_bytes == 0)
	{
		line = ft_substr(remain, 0, ft_strlen(remain));
		free(remain);
		remain = NULL;
		return (line);
	}
	return (0);
}
