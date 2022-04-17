/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:50:17 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/17 21:56:00 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include  "fdf.h"

int main()
{
	int		fd;
	char	*line;

	fd = open("10-2.fdf", O_RDONLY, 0);
	line = get_next_line(fd);
	printf("%d\n", fd);
	printf("%s\n", line);
}

// #include <stdio.h>
// #include <stdlib.h>
// void f(char *a)
// {
// 	for (int i = 0; i < 10; i++)
// 		a[i]  = 97 + i;
// }



// int main()
// {
// 	char	a[10];

// 	f(a);
// 	for(int i =0; i < 10; i++)
// 		printf("%c\n", a[i]);
// }