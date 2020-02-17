#include "get_next_line_test.h"
#include "libft.h"

int		main(void)
{
	char	**line;
	size_t	len = 10;

	if (!(line = (char **)ft_memalloc(sizeof(char *) * len)))
		return (0);
	while (len > 0)
		if (!(line[len-- - 1] = (char *)ft_memalloc(sizeof(char) * (10 + 1))))
			return (0);
	// test_1l
	ft_print_gnl("test_1l", BUFF_SIZE_50, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE0, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE2, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE4, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE5, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE6, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE7, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE8, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE9, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE10, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE50, line, get_next_line, test1);
	ft_print_gnl("test_1l", BUFF_SIZE100, line, get_next_line, test1);
	return (0);
}
