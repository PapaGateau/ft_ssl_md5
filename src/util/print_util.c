/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:32:40 by plogan            #+#    #+#             */
/*   Updated: 2019/05/13 16:02:02 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	print_for_type(unsigned char b[4], int type)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (type == MD5)
			ft_printf("%02x", b[i]);
		else if (type == SHA256)
			ft_printf("%02x", b[3 - i]);
		i++;
	}
}

void	print_digest(unsigned *digest, int type)
{
	union u_int	u;
	int			j;
	int			size;

	size = 0;
	if (ft_s()->com_id == MD5)
		size = 4;
	else if (ft_s()->com_id == SHA256)
		size = 8;
	j = 0;
	while (j < size)
	{
		u.w = digest[j];
		print_for_type(u.b, type);
		j++;
	}
}
