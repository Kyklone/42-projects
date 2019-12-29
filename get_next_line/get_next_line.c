


#include "get_next_line_test.h"
#include "libft.h"

int			get_next_line(const int fd, char **line, size_t BUFF)
{
	int				count = 0;
	int				ret;
	unsigned int	i;
	unsigned int	n;
	t_list			*lst;
	unsigned char	*cmp;

	ret = 1;
	i = 0;
	n = 0;
	lst = NULL;
	// Read file descriptor
	if ((ret = read(fd, line[count], BUFF)))
	{
		line[count][ret] = '\0';
		lst = ft_lstpush(lst, line[count]);
	}
		if (ret && lst)
			i = ft_strnlen(lst->content, BUFF);
		while (lst && !n)
		{
			ret = 0;
			ret += ft_strlen(lst->content);
			if ((cmp = (unsigned char *)ft_memchr(lst->content, '\n', ft_strlen(lst->content))))
			{
				n = cmp - (unsigned char *)lst->content;
				n += 1;
				ret -= ft_strlen(lst->content) - n;
				i -= ret;
			}
			lst = lst->next;
		}
		/*if (n && ret > 0)
		{
			ft_putstr_color("New line position in list element: ", YEL, 0);
			ft_putstr_color(ft_itoa(n), RED, 2);
			ft_putstr_color("New line location in the list: ", YEL, 0);
			ft_putstr_color(ft_itoa(i), GRE, 2);
		}
		else
		{
			ft_putstr_color("Buffer size was less than the line length", YEL, 2);
		}*/
		if (ret > 0 && !n)
			get_next_line(fd, line, BUFF);
	count++;
	return (ret);
}
