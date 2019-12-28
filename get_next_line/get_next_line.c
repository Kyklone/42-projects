


#include "get_next_line_test.h"
#include "libft.h"

/*static int	ft_find_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}*/

int			get_next_line(const int fd, char **line, size_t BUFF)
{
	int				count = 0;
	int				ret;
	unsigned int	i;
	unsigned int	n;
	t_list			*lst;
	t_list			*tmp;
	unsigned char	*cmp;

	ret = 1;
	i = 0;
	n = 0;
	lst = NULL;
	// Read file descriptor
	if ((ret = read(fd, line[count], BUFF)))
	{
		line[count][BUFF] = '\0';
		lst = ft_lstpush(lst, line[count++]);
	}
		tmp = lst;
		ft_putstr_color(ft_itoa(ret), RED);
		if (ret && lst)
			i = ft_strnlen(lst->content, BUFF);
		while (tmp && !n)
		{
			ft_putendl(tmp->content);
			ret = 0;
			ret += ft_strlen(tmp->content);
			//cmp = (unsigned char *)tmp->content;
			if ((cmp = (unsigned char *)ft_memchr(tmp->content, '\n', ft_strlen(tmp->content))))
			{
				n = cmp - (unsigned char *)tmp->content;
				n += 1;
				ret -= ft_strlen(tmp->content) - n;
				i -= ret;
			}
			tmp = tmp->next;
		}
		if (n && ret > 0)
		{
			ft_putstr_color("New line position in list element: ", YEL);
			ft_putstr_color(ft_itoa(n), RED);
			ft_putendl("");
			ft_putstr_color("New line location in the list: ", YEL);
			ft_putstr_color(ft_itoa(i), GRE);
			ft_putendl("");
			ft_putstr_color("Count: ", YEL);
			ft_putstr_color(ft_itoa(count), TEA);
			ft_putendl("");
		}
		else
		{
			ft_putstr_color("Buffer size was less than the line length", YEL);
			ft_putendl("");
		}
		if (ret > 0 && !n)
			get_next_line(fd, line, BUFF);
	return (ret);
}
