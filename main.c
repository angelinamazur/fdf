/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:18:15 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/07 18:50:25 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// int		deal_key(int key)
// {
// 	printf("%d", key); // ft_printf !
// 	return(0);
// }

int	main(void)
{
	t_map	*map;
	int		i;
	// int		j;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	read_file("t1.fdf", map);
	// printf("%d\n", map->height);
	// printf("%d\n", map->width);
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
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1920, 1080, "FDF");
	map->img = mlx_new_image(map->mlx_ptr, 1920, 1080);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, & map->line_length, &map->endian);
	map->zoom  = 20;
	draw(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,  map->img, 0, 0);
	mlx_loop(map->mlx_ptr);
}

