/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:39:21 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/18 17:44:08 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void make_env(t_env **env, int height, int width)
{
	int i;
	
	i = 0;
	(*env)->height = height;
	(*env)->width = width;
	(*env)->zoom = 20;
	(*env)->shift_x = 150;
	(*env)->shift_y = 100;
	(*env)->iso_flag = 1;
	(*env)->z_k = 1;
	(*env)->map = (t_elem **)malloc(sizeof(t_elem *) * (height + 1));
	while (i <= height)
	{
		(*env)->map[i] = (t_elem *)malloc(sizeof(t_elem) * (width + 1));
		i++;
	}
}