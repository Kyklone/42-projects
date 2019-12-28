/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:29:37 by hkortela          #+#    #+#             */
/*   Updated: 2019/11/07 18:22:11 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	wstr[10];
	int		i;

	i = 9;
	if (n > 2147483647 || n < -2147483648)
		return ;
	else if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			wstr[i--] = -(n % 10) + '0';
			n = -(n + n % 10) / 10;
		}
		n *= -1;
	}
	if (n != 0)
		wstr[i--] = n % 10 + '0';
	while ((n = (n - n % 10) / 10))
		wstr[i--] = n % 10 + '0';
	while (i < 9)
		ft_putchar(wstr[++i]);
}