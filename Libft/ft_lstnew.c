/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:15:40 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 17:35:52 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (new);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (t_list *)malloc(sizeof(content) * content_size);
		if (new->content == NULL)
			return (new->content);
		ft_memcpy((new->content), content, sizeof(content) * content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
