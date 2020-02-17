#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	**line;
	int		fd;
	int		ret;

	/*
		Problems:
		big buffer sizes with malloc
		need to free list
		test leaks
	*/
	if (argc > 1)
	{
		line = (char **)malloc(sizeof(char *));
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, line)))
		{
			close(fd);
			if (ret == -1)
			{
				ft_putstr_color("Error", RED, 1);
				break;
			}
			ft_putendl(*line);
			if (**line)
				free(*line);
		}
		ft_strdel(line);
		close(fd);
		while (1);
	}
	return (0);
}
