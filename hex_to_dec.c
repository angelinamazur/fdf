/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:37:58 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 15:38:31 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hex_to_dec(char *hex)
{
	int	dec;
	int	x;
	int	y;
	int	i;

	dec = 0;
	y = 0;
	i = ft_strlen(hex) - 1;
	if (hex[i] == '\n')
		i--;
	while (i >= 0)
	{
		if ((hex[i]) >= '0' && (hex[i]) <= '9')
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
