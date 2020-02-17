/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:30:21 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/04 19:45:06 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*c_d;
	const char	*c_s;
	size_t		dlen;
	size_t		slen;
	size_t		i;

	c_s = src;
	c_d = dst;
	dlen = ft_strnlen(dst, dstsize);
	slen = ft_strlen(src);
	i = dstsize - dlen - 1;
	if (dlen == dstsize)
		return (dstsize + slen);
	else
	{
		while (*c_d)
			c_d++;
		while (*c_s && i-- > 0)
			*c_d++ = (char)*c_s++;
		*c_d = '\0';
	}
	return (dlen + slen);
}
