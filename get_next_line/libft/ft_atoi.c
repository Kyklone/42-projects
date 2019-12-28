/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:28:11 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/13 13:38:26 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_ws_sign(const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '+')
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
				return (0);
		if (s[i] == '-')
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
				return (-1);
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else if (s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
			i++;
		else if (s[i] >= '0' && s[i] <= '9')
			return (0);
		else
			return (1);
	}
	return (0);
}

static const char	*ft_skip(const char *s)
{
	while (*s)
	{
		if (*s == '+' || *s == '-')
		{
			s++;
			break ;
		}
		else if (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		else if (*s == '\r' || *s == '\v' || *s == '\f')
			s++;
		else if (*s >= '0' && *s <= '9')
			break ;
	}
	return (s);
}

int					ft_atoi(const char *str)
{
	long long	val;
	int			i;
	int			neg;

	val = 0;
	i = 0;
	neg = 0;
	if (((neg = ft_ws_sign(str, 0)) != 1))
	{
		str = ft_skip(str);
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return ((int)val);
			if (neg == -1)
				val = val * 10 - (str[i++] - '0');
			else
				val = val * 10 + (str[i++] - '0');
			if (!(val < 9223372036854775807))
				return (-1);
			else if (!(val > -9223372036854775807))
				return (0);
		}
	}
	return ((int)val);
}
