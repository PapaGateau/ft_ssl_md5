/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:11:44 by plogan            #+#    #+#             */
/*   Updated: 2019/05/13 15:38:17 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	add_u_buffer(unsigned *dest, unsigned *add, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		dest[i] = dest[i] + add[i];
		i++;
	}
}

void	copy_buffer(char *dest, char *src, int size, int type)
{
	int		i;

	i = 0;
	while (i <= size * type - 1)
	{
		dest[i] = src[i];
		i++;
	}
}

void	atoi_big_endian(unsigned *dest, unsigned char *src, int size)
{
	int	j;
	int x;

	j = 0;
	x = 0;
	while (x < size)
	{
		dest[x] = (src[j] << 24) | (src[j + 1] << 16) | (src[j + 2] << 8) |
			(src[j + 3]);
		j += 4;
		x++;
	}
}
