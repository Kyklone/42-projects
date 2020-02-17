/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:30:03 by hkortela          #+#    #+#             */
/*   Updated: 2020/02/17 12:35:11 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **alst)
{
	size_t	n;
	t_list	*lst;

	n = 0;
	lst = *alst;
	while (lst)
	{
		n += lst->content_size;
		lst = lst->next;
	}
	return (n);
}
