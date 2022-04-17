/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:16:42 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/17 22:25:45 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fdf.h"
#include <stdio.h>

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
		if (s[i] == c)
			flag = 1;
		else if (flag)
			count++;
		if (s[i] != c)
			flag = 0;
		i++;
	}
	return (count - 1);
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
		// printf("%s", line);
		line = get_next_line(fd);
		height++;
	}
	printf("%d\n", fd);
	close(fd);
	free(line);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_word_count(line, ' ');
	// printf("%d\n", fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (width);
}

void	fill_values(int *line_v, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i])
	{
		line_v[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->height = get_height(file);
	map->width = get_width(file);
	map->values = (int **)malloc(sizeof(int *) * (map->height + 1));
	i = 0;
	while (i <= map->height)
	{
		map->values[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		i++;
	}
	fd = open(file, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	printf("%d\n", fd);
	while (line)
	{
		printf("%s\n", line);
		fill_values(map->values[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	map->values[i] = NULL;
}
