/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:42:05 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 15:20:41 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "util/util.h"

int		memjoin(char **buf1, char *buf2, int size1, int size2)
{
	char	*temp;

	if (!(temp = (char *)malloc(size1 + size2)))
		return (0);
	if (size1)
	{
		ft_memcpy(temp, *buf1, size1);
		ft_memcpy(temp + size1, buf2, size2);
		free(*buf1);
		*buf1 = temp;
	}
	else
	{
		ft_memcpy(temp, buf2, size2);
		free(*buf1);
		*buf1 = temp;
	}
	return (1);
}

char	*read_message(int fd, int *size)
{
	int		ret;
	char	*buf;
	char	*temp;

	if (!(temp = (char *)malloc(READ_BUF_SIZE)))
		return (temp);
	ret = 0;
	buf = NULL;
	while ((ret = read(fd, temp, READ_BUF_SIZE)) > 0)
	{
		if (!(memjoin(&buf, temp, *size, ret)))
			break ;
		*size = *size + ret;
	}
	if (*size)
		buf[*size] = '\0';
	if (ret == -1)
		ft_s()->err = 1;
	free(temp);
	return (buf);
}

void	dispatch_message(char *msg, int size)
{
	unsigned		*digest;
	t_hash_array	hash_array[2];

	hash_array[0] = &md5;
	hash_array[1] = &sha256;
	digest = (*hash_array[ft_s()->com_id])(msg, size);
	if (digest)
	{
		print_digest(digest, ft_s()->com_id);
		free(digest);
	}
}
