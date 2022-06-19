/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:18:15 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/19 22:39:04 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int ft_close(void)
{
	exit(0);
}

// int	ft_close(t_env *env)
// {
// 	free_map(env->map, env->height);
// 	free(env);
// 	exit(0);
// }

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
		exit(0);
	free(env->img);
	free(env->addr);
	env->img = mlx_new_image(env->mlx_ptr, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
		& env->line_length, &env->endian); // how it works
	draw(env);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	int		i;
	// int		j;

	i = 0;
	if (argc < 2)
		return (0);
	env = (t_env *)malloc(sizeof(t_env));
	read_file(argv[1], env);
	printf("height %d\n", env->height);
	printf("width %d\n", env->width);
	// while (i < env->height)
	// {
	// 	j = 0;
	// 	while (j < env->width)
	// 		printf("%3d ", env->map[i][j++].value);
	// 	i++;
	// 	printf("\n");
	// }
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, W_HEIGHT, "FDF");
	env->img = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel,\
		& env->line_length, &env->endian);
	draw(env);
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_hook(env->win_ptr, 17, 0, ft_close, NULL);
	mlx_loop(env->mlx_ptr);
	ft_close();
	return (0);
}






	// ft_bzero(env->addr, env->height * env->width * \
	//  (env->bits_per_pixel / 8));

	
		// mlx_destroy_window(env->mlx_ptr,env->win_ptr);
		// mlx_destroy_image(env->mlx_ptr, env->img);
		// free_map(env->map, env->height);
		// free(env);

	// printf("height %d\n", map->height);
	// printf("width %d\n", map->width);
	// while (i < map->height)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 		printf("%3d ", map->map[i][j++].value);
	// 	i++;
	// 	printf("\n");
	// }
	// printf("\n");
	// i = 0;
	// while (i < map->height)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 		printf("%3d ", map->map[i][j++].color);
	// 	i++;
	// 	printf("\n");
	// }