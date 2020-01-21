/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:39:13 by plogan            #+#    #+#             */
/*   Updated: 2019/05/10 17:03:38 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	round1_op(unsigned abcd[])
{
	return ((abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]));
}

unsigned	round2_op(unsigned abcd[])
{
	return ((abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]));
}

unsigned	round3_op(unsigned abcd[])
{
	return (abcd[1] ^ abcd[2] ^ abcd[3]);
}

unsigned	round4_op(unsigned abcd[])
{
	return (abcd[2] ^ (abcd[1] | ~abcd[3]));
}
