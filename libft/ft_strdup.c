/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:44 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/10 20:14:32 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cptr;
	size_t	i;

	if (!(cptr = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		cptr[i] = (char)src[i];
		i++;
	}
	cptr[i] = '\0';
	return (cptr);
}
