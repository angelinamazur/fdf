/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_badone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:25:07 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 22:45:53 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

void	isometric(t_env *env, t_dots *dots)
{
	dots->x = (dots->x - dots->y) * cos(0.8);
	dots->y = (dots->x + dots->y) * sin(0.8) - env->z;
	dots->x1 = (dots->x1 - dots->y1) * cos(0.8);
	dots->y1 = (dots->x1 + dots->y1) * sin(0.8) - env->z1;
}

void	ft_mlx_pixel_put(t_env *env, int color, t_dots dots)
{	
	char	*dst;

	if ((int)dots.x < W_WIDTH && (int)dots.y < W_HEIGHT \
		&& (int)dots.x > 0 && (int)dots.y > 0)
	{
		dst = (env->addr + ((int)dots.y * env->line_length + \
			(int)dots.x * (env->bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}

void make_zoom(t_env *env, t_dots *dots)
{
	dots->x *= env->zoom;
	dots->y *= env->zoom;
	dots->x1 *= env->zoom;
	dots->y1 *= env->zoom;
}

void make_shift(t_env *env, t_dots *dots)
{
	dots->x += env->shift_x;
	dots->y += env->shift_y;
	dots->x1 += env->shift_x;
	dots->y1 += env->shift_y;
}

void	bresenham(t_env *env, t_dots dots)
{
	float	x_del;
	float	y_del;
	int		max;
	int		color;

	color = env->map[(int)dots.y][(int)dots.x].color;
	env->z = env->map[(int)dots.y][(int)dots.x].value * (env->z_k);
	env->z1 = env->map[(int)dots.y1][(int)dots.x1].value * (env->z_k);
	make_zoom(env, &dots);
	if (env->iso_flag == 1)
		isometric(env, &dots);
	make_shift(env, &dots);
	x_del = (dots.x1 - dots.x);
	y_del = (dots.y1 - dots.y);
	max = find_max(mod(x_del), mod(y_del));
	x_del /= max;
	y_del /= max;
	while ((int)(dots.x - dots.x1) || (int)(dots.y - dots.y1))
	{
		ft_mlx_pixel_put(env, color, dots);
		dots.x += x_del;
		dots.y += y_del;
	}
}

void get_dots(t_dots *dots, int x, int y)
{
	dots->x = x;
	dots->y = y;
	if (dots->flag == 1)
	{
		dots->x1 = x + 1;
		dots->y1 = y;
	}
	else
	{
		dots->x1 = x;
		dots->y1 = y + 1;
	}
}

void	draw(t_env *env)
{
	t_dots	dots;
	int		x;
	int		y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			if (x < env->width - 1)
			{
				dots.flag = 1;
				get_dots(&dots, x, y);
				bresenham(env, dots);
			}
			if (y < env->height - 1)
			{
				dots.flag = 0;
				get_dots(&dots, x, y);
				bresenham(env, dots);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
}


// void	draw(t_env *env)
// {
// 	t_dots dots;

// 	dots.y = 0;
// 	dots.y1 = 0;
// 	while (dots.y < env->height)
// 	{
// 		dots.x = 0;
// 		while (dots.x < env->width)
// 		{
// 			if (dots.x < env->width - 1)
// 			{
// 				dots.x1 = dots.x + 1;
// 				bresenham(env, dots);
// 				dots.x1 = dots.x - 1;
// 			}
// 			if (dots.y < env->height - 1)
// 			{
// 				dots.y1 = dots.y + 1;
// 				bresenham(env, dots);
// 			}
// 			dots.x++;
// 		}
// 		dots.y++;
// 	}
// 	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
// }

