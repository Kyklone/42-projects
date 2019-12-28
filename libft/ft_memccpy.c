/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:32:17 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/10 14:09:12 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	while (n-- > 0)
	{
		*c_dst = *c_src;
		if (*c_dst++ == (unsigned char)c)
			return ((void*)c_dst);
		c_src++;
	}
	return (NULL);
}
