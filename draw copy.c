/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:25:07 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 18:08:05 by ptoshiko         ###   ########.fr       */
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

void	isometric(t_env **env)
{
	(*env)->x = ((*env)->x - (*env)->y) * cos(0.8);
	(*env)->y = ((*env)->x + (*env)->y) * sin(0.8) - (*env)->z;
}

void	ft_mlx_pixel_put(t_env *env, int color)
{	
	if (env->x < W_WIDTH && env->y < W_HEIGHT && env->x > 0 && env->y > 0)
	{
		char *dst = (env->addr + (env->y * env->line_length + \
			env->x * (env->bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}

void	bresenham(t_env *env)
{
	float	x_del;
	float	y_del;
	int		max;
	int		color;

	color = env->map[env->y][env->x].color;
	env->z = env->map[env->y][env->x].value * (env->z_k);
	env->z1 = env->map[env->y1][env->x1].value * (env->z_k);
	env->x *= env->zoom;
	env->y *= env->zoom;
	env->x1 *= env->zoom;
	env->y1 *= env->zoom;
	if (env->iso_flag == 1)
	{
		isometric(&env);
		isometric(&env);
	}
	env->x += env->shift_x;
	env->y += env->shift_y;
	env->x1 += env->shift_x;
	env->y1 += env->shift_y;
	x_del = (float)(env->x1 - env->x);
	y_del = (float)(env->y1 - env->y);
	max = find_max(mod(x_del), mod(y_del));
	x_del /= max;
	y_del /= max;
	while ((env->x - env->x1) || (env->y - env->y1))
	{
		ft_mlx_pixel_put(env, color);
		env->x += x_del;
		env->y += y_del;
	}
}

void	draw(t_env *env)
{
	env->y = 0;
	while (env->y < env->height)
	{
		env->x = 0;
		while (env->x < env->width)
		{
			if (env->x < env->width - 1)
			{
				env->x1 = env->x + 1;
				bresenham(env);
			}
			if (env->y < env->height - 1)
			{
				env->y1 = env->y + 1;
				bresenham(env);
			}
			env->x++;
		}
		env->y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
}
