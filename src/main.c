/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:15:16 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 15:23:52 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int		check_for_command(char *arg, int *pos)
{
	int	i;

	i = 0;
	while (g_com_tab[i][0])
	{
		if (!ft_strcmp(g_com_tab[i][0], arg))
		{
			ft_s()->com_id = i;
			*pos = *pos + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		is_valid_flag(char c)
{
	if (c == 'p')
		return ((ft_s()->p = true));
	if (c == 'q')
		return ((ft_s()->q = true));
	if (c == 'r')
		return ((ft_s()->r = true));
	if (c == 's')
		return ((ft_s()->s = true));
	return (0);
}

int		check_for_flags(char **argv, int *pos)
{
	int	i;

	while (argv[*pos] && argv[*pos][0] == '-' && argv[*pos][1])
	{
		i = 1;
		while (argv[*pos][i])
		{
			if (!is_valid_flag(argv[*pos][i]))
			{
				print_error(BAD_FLAG, argv[*pos] + i);
				return (0);
			}
			i++;
		}
		*pos = *pos + 1;
		if (ft_s()->s)
			return (1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int	pos;

	pos = 1;
	if (argc < 2)
	{
		print_error(USAGE, NULL);
		return (0);
	}
	if (!ft_s())
		return (0);
	if (!check_for_command(argv[pos], &pos))
	{
		print_error(BAD_COM, argv[pos]);
		return (0);
	}
	if (check_for_flags(argv, &pos))
		process_messages(argv, &pos);
	free(ft_s());
	return (0);
}
