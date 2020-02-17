/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:08:42 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/17 19:56:45 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_ws(char const *s, size_t len)
{
	size_t	i;

	i = len - 1;
	if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		return (1);
	if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		return (1);
	return (0);
}

static char		*ft_ws_clear(char const *s, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	f;
	char	*c_s;

	i = len - 1;
	k = 0;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k++;
	if (k <= i)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		i -= k - 1;
	}
	else
		i = 0;
	f = 0;
	if (!(c_s = ft_memalloc(i + 1)))
		return (NULL);
	while (f < i)
		c_s[f++] = (char)s[k++];
	c_s[f] = '\0';
	return (c_s);
}

char			*ft_strtrim(char const *s)
{
	char	*c_s;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (ft_check_ws(s, len))
		return (ft_ws_clear(s, len));
	else
	{
		if (!(c_s = ft_memalloc(len + 1)))
			return (NULL);
		ft_memcpy(c_s, s, len);
		c_s[len] = '\0';
	}
	return (c_s);
}
