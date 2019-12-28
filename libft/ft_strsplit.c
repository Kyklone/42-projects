/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:04:50 by hkortela          #+#    #+#             */
/*   Updated: 2019/12/18 13:01:37 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_c_chr(const char *s, int c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		n++;
		while (*s != (char)c && *s != '\0')
			s++;
		while (*s == (char)c && *s != '\0')
			s++;
	}
	return (n);
}

static int		ft_check_delim(char const *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (0);
	}
	return (1);
}

static char		**ft_cp_ret(char const *s)
{
	char	**new_s;
	int		i;

	i = 0;
	if (!(new_s = (char **)malloc(sizeof(char *) * (2))))
		return (NULL);
	if (!(*new_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*s)
	{
		new_s[0][i++] = (char)*s;
		s++;
	}
	new_s[0][i] = '\0';
	new_s[1] = NULL;
	return (new_s);
}

static char		**ft_trim(char const *s, char c, char **new_s, size_t count)
{
	size_t	len;
	size_t	k;
	size_t	i;
	char	*p;

	k = 0;
	while (k < count)
	{
		i = 0;
		p = (char *)s;
		while (*s != c && *s != '\0')
			s++;
		len = (unsigned char *)s - (unsigned char *)p;
		if (!(new_s[k] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		new_s[k][len--] = '\0';
		while (len-- + 1 > 0)
			new_s[k][i++] = *p++;
		k++;
		while (*s == c && *s != '\0')
			s++;
	}
	new_s[count] = (NULL);
	return (new_s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new_a;
	size_t	count;

	count = 0;
	if (s)
		if (*s)
		{
			if (ft_check_delim(s, c))
				return (ft_cp_ret(s));
			while (*s == c && *s != '\0')
				s++;
			count = ft_c_chr(s, (int)c);
			if (!(new_a = (char **)malloc(sizeof(char *) * (count + 1))))
				return (NULL);
			return (ft_trim(s, c, new_a, count));
		}
	if (!(new_a = (char **)malloc(1 * sizeof(char *))))
		return (NULL);
	new_a[0] = NULL;
	return (new_a);
}
