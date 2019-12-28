/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:27:37 by hkortela          #+#    #+#             */
/*   Updated: 2019/11/29 17:37:11 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*ltd;

	if (*alst)
	{
		ltd = *alst;
		del(ltd->content, ltd->content_size);
		ft_memdel((void**)alst);
	}
	ltd = NULL;
}
