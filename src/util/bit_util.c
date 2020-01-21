/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:08:43 by plogan            #+#    #+#             */
/*   Updated: 2019/05/13 15:38:51 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned	rotate_left(unsigned r, unsigned n)
{
	return ((r >> (32 - n)) | (r << n));
}

unsigned	rotate_right(unsigned r, unsigned n)
{
	return ((r << (32 - n)) | (r >> n));
}

unsigned	shift_right(unsigned s, unsigned n)
{
	return (s >> n);
}

unsigned	shift_left(unsigned s, unsigned n)
{
	return (s << n);
}
