/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:03:33 by hkortela          #+#    #+#             */
/*   Updated: 2019/11/10 14:14:43 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst)
	{
		tmp = *alst;
		while (tmp)
		{
			ft_lstdelone(alst, del);
			if ((tmp = tmp->next))
				*alst = tmp;
			else
				break ;
		}
	}
	tmp = NULL;
}
