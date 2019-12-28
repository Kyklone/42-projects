/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:31:15 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/16 19:30:12 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*tmp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (n > 0)
	{
		tmp = (char *)haystack;
		haystack = ft_strchr(haystack, needle[0]);
		if (haystack == NULL)
			return ((char *)haystack);
		if ((unsigned char)(haystack - tmp) <= n)
			n -= (unsigned char)(haystack - tmp);
		else
			return (NULL);
		if (n < ft_strlen(needle))
			return (NULL);
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
