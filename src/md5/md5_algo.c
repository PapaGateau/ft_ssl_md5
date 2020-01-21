/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:48:34 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 15:26:22 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "../../inc/ft_ssl.h"
#include "../util/util.h"

static void		dispatch_turn(int i, unsigned int digest[4], int *f, int *g)
{
	if (i < 16)
	{
		*f = round1_op(digest);
		*g = i;
	}
	else if (i < 32)
	{
		*f = round2_op(digest);
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = round3_op(digest);
		*g = (3 * i + 5) % 16;
	}
	else
	{
		*f = round4_op(digest);
		*g = (7 * i) % 16;
	}
}

static void		process_chunk(unsigned char *msg_p, unsigned int digest[4],
		unsigned int temp_seed[4])
{
	int				f;
	int				g;
	int				i;
	union u_mchunk	m;

	f = 0;
	i = 0;
	g = 0;
	copy_buffer((char *)m.b, (char *)msg_p, 64, 1);
	copy_buffer((char *)temp_seed, (char *)digest, 4, 4);
	while (i < 64)
	{
		dispatch_turn(i, temp_seed, &f, &g);
		f = f + temp_seed[0] + g_sin_tab[i] + m.w[g];
		temp_seed[0] = temp_seed[3];
		temp_seed[3] = temp_seed[2];
		temp_seed[2] = temp_seed[1];
		temp_seed[1] = temp_seed[1] + rotate_left(f, g_rol_tab[i]);
		i++;
	}
	add_u_buffer(digest, temp_seed, 3);
}

unsigned		*md5(const char *msg, int mlen)
{
	unsigned char	*msg_b;
	unsigned int	*digest;
	unsigned int	temp_seed[4];
	int				p;

	p = 0;
	if (!(digest = (unsigned int *)malloc(sizeof(unsigned) * 4)))
		return (NULL);
	if (!(msg_b = create_msg_b(msg, mlen, 0)))
		return (NULL);
	copy_buffer((char *)digest, (char *)g_seed_md5, 4, 4);
	while (p < SIZE_FACTOR(mlen) * 64)
	{
		process_chunk(msg_b + p, digest, temp_seed);
		p += 64;
	}
	free(msg_b);
	return (digest);
}
