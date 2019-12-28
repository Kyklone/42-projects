/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:32:17 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/10 14:07:02 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;

	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	if (dst || src)
		while (n-- > 0)
			*u_dst++ = *u_src++;
	return (dst);
}
