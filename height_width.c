/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:40:46 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 15:40:53 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	count;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\n')
			flag = 1;
		else if (flag)
			count++;
		if (s[i] != c)
			flag = 0;
		i++;
	}
	return (count);
}

int	get_width(char *line)
{
	int		width;

	width = ft_word_count(line, ' ');
	return (width);
}

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	free(line);
	return (height);
}
