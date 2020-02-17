/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:27:03 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/13 16:50:34 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!(new_s = (char *)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	if (s)
	{
		while (s[start + i] && i < len)
		{
			new_s[i] = s[start + i];
			i++;
		}
		new_s[i] = '\0';
	}
	return (new_s);
}
