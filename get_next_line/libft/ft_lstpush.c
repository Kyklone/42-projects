/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:20:33 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/28 18:04:24 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *alst, void const *content)
{
	t_list			*lst;

	lst = alst;
	if (!lst)
		alst = ft_lstnew(content, ft_strlen(content));
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = ft_lstnew(content, ft_strlen(content));
	}
	return (alst);
}
