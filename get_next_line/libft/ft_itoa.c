/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:42:06 by exam              #+#    #+#             */
/*   Updated: 2019/12/11 19:07:19 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(void)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (2))))
		return (NULL);
	str[1] = '\0';
	str[0] = '0';
	return (str);
}

static char	*ft_min(void)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_zero_or_less(int nb)
{
	int		count;
	int		tmp;
	char	*str;

	if (nb == 0)
		str = ft_zero();
	else if (nb == -2147483648)
		str = ft_min();
	else
	{
		nb *= -1;
		count = 1;
		tmp = nb;
		while ((nb = (nb - nb % 10) / 10))
			count++;
		if (!(str = (char*)malloc(sizeof(char) * (count + 1 + 1))))
			return (NULL);
		str[count + 1] = '\0';
		str[count--] = tmp % 10 + '0';
		while ((tmp = (tmp - tmp % 10) / 10))
			str[count--] = tmp % 10 + '0';
		str[count] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		count;
	char	*str;

	tmp = n;
	if (n <= 0)
		str = ft_zero_or_less(tmp);
	else
	{
		count = 1;
		while ((tmp = (tmp - tmp % 10) / 10))
			count++;
		if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
			return (NULL);
		tmp = n;
		str[count--] = '\0';
		str[count--] = tmp % 10 + '0';
		while ((tmp = (tmp - tmp % 10) / 10))
			str[count--] = tmp % 10 + '0';
	}
	return (str);
}
