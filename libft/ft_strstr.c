/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:31:15 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/15 17:55:35 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	if (needle[0] == '\0')
		return ((char *)haystack);
	haystack = ft_strchr(haystack, needle[0]);
	while (haystack)
	{
		haystack = ft_strchr(haystack, needle[0]);
		if (haystack == NULL)
			return ((char *)haystack);
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
