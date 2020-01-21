/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:43:27 by plogan            #+#    #+#             */
/*   Updated: 2019/05/21 15:32:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include "../Libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define MD5    	0
# define SHA256		1

# define USAGE		0
# define BAD_COM	1
# define BAD_FLAG	2
# define S_NO_ARG	3
# define BAD_PATH	4

# define READ_BUF_SIZE 1024

typedef unsigned		*(*t_hash_array)(const char *, int);

extern char				*g_com_tab[][2];
extern					t_hash_array g_hash_array[];

typedef struct			s_flags
{
	int		com_id;
	bool	p;
	bool	q;
	bool	r;
	bool	s;
	int		err;
}						t_flags;

/*
**		Hash algorithms
*/

unsigned				*md5(const char *msg, int mlen);
unsigned				*sha256(const char *msg, int mlen);

/*
**		Utilities
*/

t_flags					*ft_s();
void					print_error(int type, char *str);
void					print_strerror(char *path);
void					process_messages(char **argv, int *pos);
char					*read_message(int fd, int *mlen);
void					dispatch_message(char *msg, int mlen);

#endif
