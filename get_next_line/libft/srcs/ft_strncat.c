/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:30:21 by hkortela          #+#    #+#             */
/*   Updated: 2020/02/13 14:29:46 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			k;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	k = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i])
		i++;
	while (us2[k] && k < n)
		us1[i++] = us2[k++];
	us1[i] = '\0';
	return ((char *)us1);
}
