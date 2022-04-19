/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:18:15 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/19 22:45:40 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	read_file("10-2.fdf", map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	bresenham(10, 10, 600, 300, map);
	mlx_key_hook(map->win_ptr, deal_key, NULL);
	mlx_loop(map->mlx_ptr);
	// printf("%d\n", map->height);
	// printf("%d\n", map->width);
	// while (i < map->height)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 		printf("%d ", map->values[i][j++]);
	// 	i++;
	// 	printf("\n");
	// }
}
