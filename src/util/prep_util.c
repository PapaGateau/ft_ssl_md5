/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:59:47 by plogan            #+#    #+#             */
/*   Updated: 2019/05/13 15:33:52 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned char	*create_msg_b(const char *msg, int mlen, int big_endian)
{
	unsigned char	*msg_b;
	int				i;
	union u_long	u;

	if (!(msg_b = (unsigned char *)malloc(64 * SIZE_FACTOR(mlen))))
		return (msg_b);
	ft_memcpy(msg_b, msg, mlen);
	msg_b[mlen] = 0x80;
	i = mlen + 1;
	while (i < 64 * SIZE_FACTOR(mlen))
		msg_b[i++] = 0;
	u.w = 8 * mlen;
	if (!big_endian)
		ft_memcpy(msg_b + (64 * SIZE_FACTOR(mlen)) - 8, &u.w, 8);
	else
	{
		i = 0;
		while (i < 8)
		{
			ft_memcpy(msg_b + (64 * SIZE_FACTOR(mlen)) - i - 1, u.b + i, 1);
			i++;
		}
	}
	return (msg_b);
}
