/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:18:15 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/16 21:10:51 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// 126 up
// 125 down
// 123 left
// 124 right


int		deal_key(int key, t_env *env)
{
	printf("key %d\n", key);
	if (key == 126)
		env->shift_y -= 10;
	if (key == 125)
		env->shift_y += 10;
	if (key == 123)
		env->shift_x -= 10;
	if (key == 124)
		env->shift_x += 10;
	free(env->img);
	ft_bzero(env->addr, env->height * env->width * \
	 (env->bits_per_pixel / 8));
	// free(env->addr);
	env->img = mlx_new_image(env->mlx_ptr, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, & env->line_length, &env->endian);
	// mlx_clear_window(env->mlx_ptr, env->win_ptr);
	// if (key == 53)
	// {
	// 	mlx_destroy_window(env->mlx_ptr,env->win_ptr);
	// 	mlx_destroy_image(env->mlx_ptr, env->img);
	// 	ft_free_map(env);
	// }
	// mlx_clear_window(map->mlx_ptr,map->win_ptr);
	// free(map->addr);
	// mlx_destroy_image (map->mlx_ptr, map->img);
	draw(env);
	return(0);
}

int	main(void)
{
	t_env	*env;
	int		i;
	// int		j;

	i = 0;
	env = (t_env *)malloc(sizeof(t_env));
	read_file("42.fdf", env);
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
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, 1920, 1080, "FDF");
	env->img = mlx_new_image(env->mlx_ptr, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, & env->line_length, &env->endian);
	draw(env);
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_loop(env->mlx_ptr);
	// free(map);
	return(0);
}

