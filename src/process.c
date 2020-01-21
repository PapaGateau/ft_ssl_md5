/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:23:35 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 15:25:08 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int		process_string(char **argv, int *pos)
{
	int	mlen;

	mlen = 0;
	if (!argv[*pos])
	{
		print_error(S_NO_ARG, NULL);
		return (0);
	}
	if (!ft_s()->r && !ft_s()->q)
		ft_printf("%s (\"%s\") = ", g_com_tab[ft_s()->com_id][1], argv[*pos]);
	dispatch_message(argv[*pos], ft_strlen(argv[*pos]));
	if (ft_s()->r && !ft_s()->q)
		ft_printf(" \"%s\"", argv[*pos]);
	ft_printf("\n");
	ft_s()->s = false;
	return (1);
}

int		process_stdout(void)
{
	int		mlen;
	char	*msg;

	mlen = 0;
	msg = read_message(0, &mlen);
	if (ft_s()->p && msg)
	{
		ft_printf("%s", msg);
		dispatch_message(msg, mlen);
	}
	else
		dispatch_message(msg, mlen);
	ft_printf("\n");
	free(msg);
	return (1);
}

int		process_path(char *path)
{
	int		fd;
	int		mlen;
	char	*msg;

	mlen = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		print_error(BAD_PATH, path);
		return (1);
	}
	msg = read_message(fd, &mlen);
	if (ft_s()->err)
	{
		print_strerror(path);
		return (1);
	}
	if (!ft_s()->r && !ft_s()->q)
		ft_printf("%s (%s) = ", g_com_tab[ft_s()->com_id][1], path);
	dispatch_message(msg, mlen);
	if (ft_s()->r && !ft_s()->q)
		ft_printf(" %s", path);
	ft_printf("\n");
	free(msg);
	return (1);
}

void	process_messages(char **argv, int *pos)
{
	if ((ft_s()->p || (!argv[*pos] && !ft_s()->s)) && !process_stdout())
		return ;
	while (argv[*pos] || ft_s()->s)
	{
		if (ft_s()->s)
		{
			if (!process_string(argv, pos))
				break ;
		}
		else if (!process_path(argv[*pos]))
			break ;
		*pos = *pos + 1;
	}
}
