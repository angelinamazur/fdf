/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:01:38 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 15:41:07 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color(char *str, int value)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j = i;
		i++;
	}
	if (j == 0)
	{
		if (value == 0)
			color = 16777215;
		if (value > 0)
			color = 15463513;
		if (value < 0)
			color = 5444021;
	}
	else
		color = ft_hex_to_dec (str + j + 3);
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
		map[i].color = ft_color(num[i], map[i].value);
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *file, t_env *env)
{
	int		fd;
	char	*line;
	int		i;
	int		height;
	int		width;

	height = get_height(file);
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	width = get_width(line);
	make_env(env, height, width);
	i = 0;
	while (line)
	{
		fill_values(env->map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
}
