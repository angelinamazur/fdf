/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:01:38 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/07 13:53:13 by ptoshiko         ###   ########.fr       */
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
		line = get_next_line(fd);
		free(line);
		height++;
	}
	close(fd);
	free(line);
	return (height);
}

int ft_hextodec(char *hex)
{
	int dec;
	int x;
	int y;
	int i;
	
	dec = 0;
	y = 0;
	i = ft_strlen(hex) - 1;
	while (i >= 0)
	{
		if((hex[i]) >= '0' && (hex[i]) <= '9')
			x = hex[i] - '0';
		if ((hex[i]) >= 'A' && (hex[i]) <= 'F')
			x = hex[i] - 'A' + 10;
		if ((hex[i]) >= 'a' && (hex[i]) <= 'f')
			x = hex[i] - 'a' + 10;
		dec = dec + x * pow(16, y);
		i--;
		y++;
	}
	return (dec);
}

int ft_color(char *str)
{
	int color;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j = i;
		i++;
	}
	if (j == 0)
		color = 16777215;
	else
		color = ft_hextodec (str + j + 3);
	return (color);
}

void	fill_values(t_elem *map, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i]) 
	{
		map[i].value = ft_atoi(num[i]);
		map[i].color = ft_color(num[i]);
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
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	map->width = get_width(line);
	map->map = (t_elem **)malloc(sizeof(t_elem *) * (map->height + 1));
	i = 0;
	while (i <= map->height)
	{
		map->map[i] = (t_elem *)malloc(sizeof(t_elem) * (map->width + 1));
		i++;
	}
	i = 0;
	while (line)
	{
		fill_values(map->map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	map->map[i] = NULL;
}