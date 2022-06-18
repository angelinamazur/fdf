/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:33:16 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/18 17:33:55 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void move(int key, t_env *env)
{
	if (key == UP)
		env->shift_y -= 10;
	if (key == DOWN)
		env->shift_y += 10;
	if (key == LEFT)
		env->shift_x -= 10;
	if (key == RIGHT)
		env->shift_x += 10;
}

void zoom(int key, t_env *env)
{
	if (key == ZOOM_IN && env->zoom > 0)
		env->zoom -= 1;
	if (key == ZOOM_OUT)
		env->zoom += 1;
}

void iso(int key, t_env *env)
{
	if (key == ISO_ON)
		env->iso_flag = 1;
	if (key == ISO_OFF)
		env->iso_flag = 0;
}

void flatten(int key, t_env *env)
{
	if (key == Z_UP)
		env->z_k += 1;
	if (key == Z_DOWN)
		env->z_k -= 1;
}