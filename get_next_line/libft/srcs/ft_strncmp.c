/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:30:37 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/13 13:49:21 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (s1 && s2)
		while (*s1 && *s2 && n > 1)
		{
			if (*s1 != *s2)
				break ;
			s1++;
			s2++;
			n--;
		}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
