/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:25:30 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 15:25:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

t_flags		*ft_s(void)
{
	t_flags static	*flags;

	if (!flags)
	{
		if (!(flags = (t_flags *)malloc(sizeof(t_flag))))
			return (flags);
		flags->com_id = -1;
		flags->p = false;
		flags->q = false;
		flags->r = false;
		flags->s = false;
		flags->err = 0;
	}
	return (flags);
}
