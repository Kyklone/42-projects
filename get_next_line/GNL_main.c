#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line_test.h"

#define PRINT_WS			70
#define 	  lt			"<<<<<<<< "
#define		  gt			" >>>>>>>>"
#define		  bd			"____________________________________________"
#define		  bdl			ft_strlen(bd)

// Print white spaces.
int		ft_print_ws(size_t len)
{
	int		n;

	n = (int)len;
	while (len-- > 0)
		write(1, " ", 1);
	return (n);
}

// Print header for current file being tested.
void	ft_print_h(const char *s)
{
	ft_putchar('\n');
	// Print white spaces
	ft_print_ws(PRINT_WS / 2 - ft_strlen(ft_strjoin(ft_strjoin(lt, s), gt)) / 2);
	// Print header
	ft_putendl(ft_strjoin(ft_strjoin(ft_strjoin(lt, s), gt), "\n"));
}

// Function to call gnl as f-pointer. Also writes buffer size and how many bites have been read.
void	ft_print_gnl(const char *path, int buffer, char **line, int (*f)(int, char **, size_t))
{
	char	*bor;
	if (!(bor = (char *)ft_memalloc(bdl + 1)))
		return ;
	bor[bdl] = '\0';
	size_t	len = ft_strlen(path);
	size_t	i = bdl / 2 - len / 2;
	size_t	k = 0;
	ft_strcpy(bor, bd);
	// Replace part of border with file name
	while (k < len)
	{
		bor[i + k] = ft_toupper(bor[i + k] = path[k]);
		k++;
	}
	printf("%s%s%s\n\n", TEA, bor, NC);
	int	fd = open(path, O_RDONLY);
	int	z = f(fd, line, buffer);
	printf("%sBUFF_SIZE%s..%d	%sReading returned%s..%d\n", BLU, NC, buffer, BLU, NC, z);
	close(fd);
	printf("%s%s%s\n\n\n", TEA, NC, bd);
}
