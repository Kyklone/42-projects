/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:25:16 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/10 15:22:47 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_s;

	if (!(new_s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(new_s, size);
	new_s[size] = '\0';
	return (new_s);
}
