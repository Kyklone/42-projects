/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:30:28 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/11 18:38:05 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = (char*)s;
	while (*s)
	{
		if (*s == (char)c)
			tmp = (char*)s;
		s++;
	}
	if (*tmp == (char)c)
		return (tmp);
	if ((char)c == '\0')
		return ((char*)s);
	return (NULL);
}
