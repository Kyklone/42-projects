#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line_test.h"

#define PRINT_WS	70
#define lt			"<<<<<<<< "
#define	gt			" >>>>>>>>"
#define	bd			"____________________________________________"
#define	bdl			ft_strlen(bd)

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
void	ft_print_gnl(const char *path, int buffer, char **line, int (*f)(int, char **, size_t), int linelen)
{
	char	*bor;	
	size_t	len = ft_strlen(path);
	size_t	i = bdl / 2 - len / 2;
	size_t	k = 0;

	if (!(bor = (char *)ft_memalloc(bdl + 1)))
		return ;
	bor[bdl] = '\0';
	ft_strcpy(bor, bd);

	// Replace part of border with file name
	bor = ft_replace(bor, path, i, 0);
	while (k < len)
	{
		bor[k + i] = ft_toupper(bor[k + i] = path[k]);
		k++;
	}

	ft_putstr_color(bor, TEA, 2);
	int	fd = open(path, O_RDONLY);
	int	z = f(fd, line, buffer);
	ft_putstr_color(" BUFF_SIZE..", BLU, 0);
	ft_putstr_color(ft_itoa(buffer), NC, 0);
	ft_putstr_color("	Reading returned..", BLU, 0);
	ft_putstr_color("[ ", NC, 0);
	if (z == linelen)
		ft_putstr_color(ft_itoa(z), GRE, 0);
	else
		ft_putstr_color(ft_itoa(z), RED, 0);
	ft_putstr_color(" ]", NC, 1);
	ft_putstr_color(bd, TEA, 2);
	close(fd);
}
