/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:01:03 by plogan            #+#    #+#             */
/*   Updated: 2019/05/13 15:37:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "../../inc/ft_ssl.h"

# define SIZE_FACTOR(x) ((x + 8) % 64 ? 1 + (x + 8) / 64 : (x + 8) / 64)

typedef union		u_long
{
	long			w;
	unsigned char	b[8];
}					t_long;

typedef union		u_int
{
	unsigned		w;
	unsigned char	b[4];
}					t_wbs;

/*
**					Hash processing utilities
*/

unsigned char		*create_msg_b(const char *msg, int mlen, int big_endian);
void				print_digest(unsigned *digest, int type);

/*
**					Buffer processing utilities
*/

void				add_u_buffer(unsigned *dest, unsigned *add, int size);
void				copy_buffer(char *dest, char *src, int size, int type);
void				atoi_big_endian(unsigned *dest, unsigned char *src,
		int size);

/*
**					Bit operators
*/

unsigned			rotate_left(unsigned r, unsigned n);
unsigned			rotate_right(unsigned r, unsigned n);
unsigned			shift_left(unsigned s, unsigned n);
unsigned			shift_right(unsigned s, unsigned n);

#endif
