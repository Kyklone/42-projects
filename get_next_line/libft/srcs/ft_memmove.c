/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:27:56 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/16 14:24:25 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < (void *)src)
		return (ft_memcpy(dst, src, len));
	else if (dst || src)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	return (dst);
}
