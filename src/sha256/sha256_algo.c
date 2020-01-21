/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:45:21 by plogan            #+#    #+#             */
/*   Updated: 2019/05/13 15:31:00 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"
#include "../../inc/ft_ssl.h"
#include "../util/util.h"

static void	extend_words(unsigned int chunk[64])
{
	int			i;
	unsigned	s0;
	unsigned	s1;

	i = 16;
	while (i < 64)
	{
		s0 = rotate_right(chunk[i - 15], 7) ^ rotate_right(chunk[i - 15], 18) ^
			shift_right(chunk[i - 15], 3);
		s1 = rotate_right(chunk[i - 2], 17) ^ rotate_right(chunk[i - 2], 19) ^
			shift_right(chunk[i - 2], 10);
		chunk[i] = chunk[i - 16] + s0 + chunk[i - 7] + s1;
		i++;
	}
}

static void	compression_loop(unsigned temp_seed[8], unsigned temp1, int i,
	unsigned chunk[64])
{
	unsigned		ch;
	unsigned		maj;
	unsigned		s0;
	unsigned		s1;

	s1 = rotate_right(temp_seed[4], 6) ^ rotate_right(temp_seed[4], 11) ^
		rotate_right(temp_seed[4], 25);
	ch = (temp_seed[4] & temp_seed[5]) ^ (~temp_seed[4] & temp_seed[6]);
	temp1 = temp_seed[7] + s1 + ch + g_root_tab[i] + chunk[i];
	s0 = rotate_right(temp_seed[0], 2) ^ rotate_right(temp_seed[0], 13) ^
		rotate_right(temp_seed[0], 22);
	maj = (temp_seed[0] & temp_seed[1]) ^ (temp_seed[0] & temp_seed[2]) ^
		(temp_seed[1] & temp_seed[2]);
	temp_seed[7] = temp_seed[6];
	temp_seed[6] = temp_seed[5];
	temp_seed[5] = temp_seed[4];
	temp_seed[4] = temp_seed[3] + temp1;
	temp_seed[3] = temp_seed[2];
	temp_seed[2] = temp_seed[1];
	temp_seed[1] = temp_seed[0];
	temp_seed[0] = temp1 + s0 + maj;
}

static void	process_chunk(unsigned char *msg_p, unsigned int digest[8],
		unsigned int temp_seed[8])
{
	int				i;
	union u_mchunk	m;
	unsigned		temp1;

	i = 0;
	temp1 = 0;
	atoi_big_endian(m.w, msg_p, 16);
	extend_words(m.w);
	copy_buffer((char *)temp_seed, (char *)digest, 8, 4);
	while (i < 64)
	{
		compression_loop(temp_seed, temp1, i, m.w);
		i++;
	}
	add_u_buffer(digest, temp_seed, 8);
}

unsigned	*sha256(const char *msg, int mlen)
{
	unsigned char	*msg_b;
	unsigned int	*digest;
	unsigned int	temp_seed[8];
	int				p;

	p = 0;
	if (!(digest = (unsigned int *)malloc(sizeof(unsigned) * 8)))
		return (NULL);
	if (!(msg_b = create_msg_b(msg, mlen, 1)))
		return (NULL);
	copy_buffer((char *)digest, (char *)g_seed_sha256, 8, 4);
	while (p < SIZE_FACTOR(mlen) * 64)
	{
		process_chunk(msg_b + p, digest, temp_seed);
		p += 64;
	}
	free(msg_b);
	return (digest);
}
