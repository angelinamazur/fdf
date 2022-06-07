/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:25:07 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/07 18:48:29 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <unistd.h>

int	find_max(float a, float b)
{
	int	max;

	if (a > b)
		max = a;
	else
		max = b;
	return (max);
}

float	mod(float i)
{	
	if (i < 0)
		return (-i);
	else
		return (i);
}

void isometric(float *x, float *y, int z) // ?
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void ft_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color; 
}

void	bresenham(float x, float y, float x1, float y1, t_map *map)
{
	float	x_del;
	float	y_del;
	int		max;
	int		color;
	int		z;
	int		z1;
	
	color = map->map[(int)y][(int)x].color;
	z = map->map[(int)y][(int)x].value;
	z1 = map->map[(int)y1][(int)x1].value;
	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;
	
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x +=100;
	y +=100;
	x1 +=100;
	y1 +=100;
	// 0xFF0000 16711680
	// map->map[(int)y][(int)x].color
	// y1 +=150;
	
	x_del = x1 - x;
	y_del = y1 - y;
	max = find_max(mod(x_del), mod(y_del));
	x_del /= max;
	y_del /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		ft_mlx_pixel_put(map, x, y, color);
		x += x_del;
		y += y_del;
	}
}

void draw(t_map *map)
{
	int x;
	int y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			if (x < map->width - 1)
				bresenham(x, y, x + 1, y, map);
			if (y < map->height - 1)
				bresenham(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}