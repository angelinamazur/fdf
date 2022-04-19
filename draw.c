/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:25:07 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/19 22:43:32 by ptoshiko         ###   ########.fr       */
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

void	bresenham(int x1, int y1, int x2, int y2, t_map *map)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x2 - x1;
	y_step = y2 - y1;
	max = find_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y2, 0xffffff);
		x1 += x_step;
		y1 += y_step;
	}
}
