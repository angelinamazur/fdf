/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:25:07 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/17 20:09:26 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // clean 

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

void ft_mlx_pixel_put(t_env *data, int x, int y, int color)
{	
	if (x < W_WIDTH && y < W_HEIGHT && x > 0 && y > 0)
	{
		char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color; 
	}
}

void	bresenham(float x, float y, float x1, float y1, t_env *env)
{
	float	x_del;
	float	y_del;
	int		max;
	int		color;
	int		z;
	int		z1;
	
	color = env->map[(int)y][(int)x].color;
	z = env->map[(int)y][(int)x].value;
	z1 = env->map[(int)y1][(int)x1].value;
	
	x *= env->zoom;
	y *= env->zoom;
	x1 *= env->zoom;
	y1 *= env->zoom;
	
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	
	x += env->shift_x;
	y += env->shift_y;
	x1 += env->shift_x;
	y1 += env->shift_y;
	
	x_del = x1 - x;
	y_del = y1 - y;
	max = find_max(mod(x_del), mod(y_del));
	x_del /= max;
	y_del /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		ft_mlx_pixel_put(env, x, y, color);
		x += x_del;
		y += y_del;	
	}
}

void draw(t_env *env)
{
	int x;
	int y;
 
	y = 0;
	while (y < env->height)
	{
		x = 0;
		while(x < env->width)
		{
			if (x < env->width - 1)
				bresenham(x, y, x + 1, y, env);
			if (y < env->height - 1)
				bresenham(x, y, x, y + 1, env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,  env->img, 0, 0);
}