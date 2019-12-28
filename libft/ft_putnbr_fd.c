/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:16:45 by hkortela          #+#    #+#             */
/*   Updated: 2019/11/10 16:03:20 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	wstr[10];
	int		i;

	i = 9;
	if (n > 2147483647 || n < -2147483648)
		return ;
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(wstr[++i], fd);
}
