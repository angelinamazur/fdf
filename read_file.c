/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:01:38 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/03 17:38:39 by ptoshiko         ###   ########.fr       */
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

// void	fill_values(int *line_v, char *line)
// {
// 	char	**num;
// 	int		i;

// 	num = ft_split(line, ' ');
// 	i = 0;
// 	while (num[i]) 
// 	{
// 		line_v[i] = ft_atoi(num[i]); // here color ?
// 		free(num[i]);
// 		i++;
// 	}
// 	free(num);
// }

int ft_hex_atoi(char *str)
{
	int i;
	char *s;

	s = "0123456789ABCDEF";
	while (str[i] != ',') // to hex 
		i++; 
	if (str[i]) = 
	
}


void	fill_value(t_elem *map, char *line)
{
	char	**num;
	int		i;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i]) 
	{
		map[i].value = ft_atoi(num[i]);
		map[i].color = ft_hexatoi(num[i]);
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
	int		j;

	map->height = get_height(file);
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd); // ? close 
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
}
	
// 	map->values = (int **)malloc(sizeof(int *) * (map->height + 1));
// 	i = 0;
// 	while (i <= map->height)
// 	{
// 		map->values[i] = (int *)malloc(sizeof(int) * (map->width + 1));
// 		i++;
// 	}
// 	i = 0;
// 	while (line)
// 	{
// 		fill_values(map->values[i], line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	close(fd);
// 	free(line);
// 	map->values[i] = NULL;
// }
}
