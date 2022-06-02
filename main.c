/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:18:15 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/02 20:43:41 by ptoshiko         ###   ########.fr       */
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
	int		j;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	read_file("42.fdf", map);
	// printf("%d\n", map->height);
	// printf("%d\n", map->width);
	// while (i < map->height)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 		printf("%3d ", map->values[i][j++]);
	// 	i++;
	// 	printf("\n");
	// }
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	map->zoom  = 20;
	draw(map);
	mlx_loop(map->mlx_ptr);
}
