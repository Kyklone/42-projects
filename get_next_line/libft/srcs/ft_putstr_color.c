/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:30:07 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/28 18:56:58 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char const *s, char const *color, int nl)
{
	if (s)
	{
		write(1, color, ft_strlen(color));
		write(1, s, ft_strlen(s));
		write(1, NC, ft_strlen(NC));
		if (nl)
			while (nl-- > 0)
				write(1, "\n", 1);
	}
}
