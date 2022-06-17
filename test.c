/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:50:17 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/17 22:02:25 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"



// int ft_hextodec(char *hex)
// {
// 	int dec;
// 	int x;
// 	int y;
// 	int i;
	
// 	dec = 0;
// 	y = 0;
// 	i = ft_strlen(hex) - 1;
// 	while (i >= 0)
// 	{
// 		if((hex[i]) >= '0' && (hex[i]) <= '9')
// 			x = hex[i] - '0';
// 		if ((hex[i]) >= 'A' && (hex[i]) <= 'F')
// 			x = hex[i] - 'A' + 10;
// 		if ((hex[i]) >= 'a' && (hex[i]) <= 'f')
// 			x = hex[i] - 'a' + 10;
// 		dec = dec + x * pow(16, y);
// 		i--;
// 		y++;
// 	}
// 	return (dec);
// }

// int main(void)
// {
// 	int a;
	
// 	a = ft_hextodec("FFFFFF");
// 	printf("%d", a);
// }

int create_color(int r, int g, int b) // demical but colors in hex 
{
	return ((r * 256 * 256) + (g * 256) + b);	
}

// int main (void)
// {
// 	printf("%d", create_color(80, 54, 132));
// }

void from_dec_to_bi(int d)
{
	while (d >= 1)
	{
		printf ("%d", d % 2);
		d = d / 2;
	}
	printf("\n");
}

int main(void)
{
	from_dec_to_bi(80);
	from_dec_to_bi(54);
	from_dec_to_bi(132);
	from_dec_to_bi(create_color(80, 54, 132));
}