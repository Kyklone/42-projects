/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:26:17 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/19 16:22:15 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstcat(t_list **alst)
{
	t_list	*lst;
	size_t	len;
	char	*nstr;

	lst = *alst;
	len = 0;
	while (lst && lst->next)
	{
		len += ft_strlen((const char *)lst->content);
		lst = lst->next;
	}
	nstr = ft_strnew(len);
	lst = *alst;
	while (lst && lst->next)
	{
		ft_putendl(lst->content);
		//ft_strcat(nstr, lst->content);
		//if (!(ft_strlcat(nstr, lst->content, len) == len))
		//{
		//	free(nstr);
		//	return (NULL);
		//}
		lst = lst->next;
	}
	return (nstr);
}
