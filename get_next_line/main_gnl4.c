#include "get_next_line_test.h"
#include "libft.h"

int		main(void)
{
	char	**line;
	size_t	len = 9;

	if (!(line = (char **)ft_memalloc(sizeof(char *) * len)))
		return (0);
	while (len > 0)
		if (!(line[len-- - 1] = (char *)ft_memalloc(sizeof(char) * 10)))
			return (0);
	// test_2l_nll
	ft_print_gnl("test_2l_nl", BUFF_SIZE_50, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE0, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE2, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE4, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE6, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE8, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE10, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE50, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE100, line, get_next_line);
	return (0);
}
