/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:04:30 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/18 14:43:57 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_t;

	if (!(new_t = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		new_t->content = (void *)malloc(content_size);
		if (!new_t->content)
		{
			free(new_t->content);
			return (NULL);
		}
		ft_memcpy(new_t->content, content, content_size);
		new_t->content_size = content_size;
	}
	else
	{
		new_t->content = NULL;
		new_t->content_size = 0;
	}
	new_t->next = NULL;
	return (new_t);
}
