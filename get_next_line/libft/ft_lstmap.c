/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:03:06 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/18 14:51:21 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new_t;

	tmp = NULL;
	if (lst)
	{
		tmp = f(ft_lstnew(lst->content, lst->content_size));
		new_t = tmp;
		while ((lst = lst->next))
		{
			new_t->next = f(lst);
			new_t = new_t->next;
		}
	}
	return (tmp);
}
