/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:18:15 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 18:36:12 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	ft_close(t_env *env)
{
	free_map(env->map, env->height);
	free(env);
	exit(0);
}

int	deal_key(int key, t_env *env)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, env);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, env);
	if (key == ISO_OFF || key == ISO_ON)
		iso(key, env);
	if (key == Z_DOWN || key == Z_UP)
		flatten (key, env);
	if (key == ESC)
		ft_close(env);
	free(env->img);
	free(env->addr);
	env->img = mlx_new_image(env->mlx_ptr, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
		& env->line_length, &env->endian);
	draw(env);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	env = (t_env *)malloc(sizeof(t_env));
	read_file(argv[1], env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, W_HEIGHT, "FDF");
	env->img = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
		& env->line_length, &env->endian);
	draw(env);
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_hook(env->win_ptr, 17, 0, ft_close, env);
	mlx_loop(env->mlx_ptr);
	ft_close(env);
	return (0);
}
