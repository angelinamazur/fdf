/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:50:17 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/05 17:51:36 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"

int ft_hextodec(char *hex)
{
	int dec;
	int x;
	int y;
	int i;
	
	dec = 0;
	y = 0;
	i = ft_strlen(hex) - 1;
	while (i >= 0)
	{
		if((hex[i]) >= '0' && (hex[i]) <= '9')
			x = hex[i] - '0';
		if ((hex[i]) >= 'A' && (hex[i]) <= 'F')
			x = hex[i] - 'A' + 10;
		if ((hex[i]) >= 'a' && (hex[i]) <= 'f')
			x = hex[i] - 'a' + 10;
		dec = dec + x * pow(16, y);
		i--;
		y++;
	}
	return (dec);
}

int main(void)
{
	int a;
	
	a = ft_hextodec("FFFFFF");
	printf("%d", a);
}