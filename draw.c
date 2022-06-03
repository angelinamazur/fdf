/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:25:07 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/03 16:43:18 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	bresenham(float x, float y, float x1, float y1, t_map *map)
{
	float	x_del;
	float	y_del;
	int		max;
	int		z;
	int		z1;
	
	z = map->values[(int)y][(int)x];
	z1 = map->values[(int)y1][(int)x1];

	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;
	
	if (z > 0 || z1 > 0)
		map->color = 0xe80c0c;
	else
		map->color = 0xffffff;
	
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	// x +=150;
	// y +=150;
	// x1 +=150;
	// y1 +=150;
	
	x_del = x1 - x;
	y_del = y1 - y;
	
	max = find_max(mod(x_del), mod(y_del));
	x_del /= max;
	y_del /= max;
	
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->map.color);
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