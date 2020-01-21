/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:05:31 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 16:37:40 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

void	print_strerror(char *path)
{
	ft_printf("ft_ssl: %s: %s\n", path, strerror(errno));
	ft_s()->err = 0;
}

void	print_error(int type, char *str)
{
	if (type == S_NO_ARG)
	{
		ft_printf("ft_ssl: option requires an argument -- s\n");
	}
	if (type == BAD_COM)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nStanda", str);
		ft_printf("rd commands:\n\nMessage Digest commands:\nmd5\nsha256");
		ft_printf("\n\nCipher commands:\n");
	}
	if (type == BAD_FLAG)
	{
		ft_printf("ft_ssl: illegal option -- %c\n", str[0]);
	}
	if (type == BAD_PATH)
	{
		ft_printf("ft_ssl: %s: No such file or directory\n", str);
	}
	if (type == USAGE || type == S_NO_ARG || type == BAD_FLAG)
	{
		ft_printf("usage: ft_ssl command [-pqr] [-s string] [files ...]\n");
	}
}
