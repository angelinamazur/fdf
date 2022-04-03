/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:16:42 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/03 22:20:28 by ptoshiko         ###   ########.fr       */
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
		printf("%s", line);
		line = get_next_line(fd);
		height++;
	}
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
	printf("line %s\n", line);
	width = ft_word_count(line, ' ');
	close(fd);
	free(line);
	return (width);
}

void	fill_values(t_map *map, char *line)
{
	
}

int	**get_values(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int		**values;
	char	*line;

	values = (int **)malloc(sizeof(int *) * (map->height + 1));
	i = 0;
	while (i <= map->height)
	{
		map->values[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		i++;
	}
	fd = open(file, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_values(map, line);
		line = get_next_line(fd);
	}
	free(line);
}

void	read_file(char *file, t_map *map)
{
	map->height = get_height(file);
	map->width = get_width(file);
	map->values = get_values(file, map);
}
