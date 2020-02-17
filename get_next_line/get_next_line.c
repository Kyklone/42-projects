/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:08:51 by hkortela          #+#    #+#             */
/*   Updated: 2020/02/17 12:30:37 by hkortela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_ret(int ret, int n, char *s, char *p)
{
	if (s[0] || n)
		return (1);
	if (!ret && p)
		free(p);
	if (!ret)
		return (0);
	return (-1);
}

static char	*ft_lstconc(t_list *lst)
{
	char	*str;
	t_list	*tmp;

	tmp = lst;
	if (!(str = (char *)ft_memalloc(ft_lstlen(&lst) + 1)))
		return (0);
	while (lst)
	{
		ft_strncat(str, lst->content, lst->content_size);
		lst = lst->next;
	}
	while (tmp)
	{
		lst = tmp;
		tmp = tmp->next;
		free(lst->content);
		lst->content_size = 0;
		free(lst);
	}
	return (str);
}

static int	ft_find_nl(t_list *lst, const int fd, char *ptr[], size_t i)
{
	t_list	*tmp;
	char	*s;
	size_t	len;

	tmp = lst;
	while (tmp)
	{
		//((char *)(tmp->content))[tmp->content_size] = '\0';
		if (!tmp->next)
			if ((s = (char *)ft_memchr(tmp->content, '\n', tmp->content_size)))
			{
				i = s - (char *)tmp->content;
				len = tmp->content_size - i;
				ptr[fd] = ft_strsub(tmp->content, i + 1, len);
				tmp->content_size = i;
				//((char *)(tmp->content))[i] = '\0';
				return (1);
			}
		tmp = tmp->next;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*ptr[4864];
	int				ret;
	int				n;
	t_list			*lst;

	ret = 1;
	if ((n = (int)BUFF_SIZE) > 0)
	{
		lst = NULL;
		if (ptr[fd])
			lst = ft_lstpush(lst, ptr[fd]);
		if (ptr[fd])
			free(ptr[fd]);
		while (!(n = ft_find_nl(lst, fd, ptr, 0)) && ret > 0)
		{
			if (!(ptr[fd] = (char *)ft_memalloc(BUFF_SIZE + 1)))
				return (0);
			if ((ret = read(fd, ptr[fd], BUFF_SIZE)))
				lst = ft_lstpush(lst, ptr[fd]);
			if (ret)
				free(ptr[fd]);
		}
		*line = ft_lstconc(lst);
	}
	return (ft_ret(ret, n, *line, ptr[fd]));
}
