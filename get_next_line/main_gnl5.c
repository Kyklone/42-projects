#include "get_next_line_test.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**line;
		size_t	len = 8; // Eight tests.
		if (!(line = (char **)ft_memalloc(sizeof(char *) * len)))
			return (0);
		while (len > 0)
			if (!(line[len-- - 1] = (char *)ft_memalloc(sizeof(char) * 10)))
				return (0);	
		ft_print_gnl(argv[1], BUFF_SIZE_50, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE0, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE2, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE4, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE8, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE10, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE50, line, get_next_line);
		ft_print_gnl(argv[1], BUFF_SIZE100, line, get_next_line);
	}
	return (0);
}
