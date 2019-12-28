#include "get_next_line_test.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define PRINT_WS			70
#define 	  lt			"<<<<<<<< "
#define		  gt			" >>>>>>>>"

/*static void		*ft_strconv(const void *s2)
{
	const char	*tmp;
	char		*n_s;
	size_t		count;
	size_t		i;

	tmp = (const char *)s2;
	count = 2;
	while (*tmp)
	{
		if ((ft_isprint((int)(*(char *)s2))) == 1)
			count += 1;
		else
			count += 2;
		tmp++;
	}
	tmp = NULL;
	if (!(n_s = ft_memalloc(count)))
		return (NULL);
	n_s[count] = '\0';
	i = 0;
	while (i < count)
	{
		if (i == 0)
			n_s[i++] = '"';
		if ((ft_isprint((*(unsigned char *)s2))) == 1)
			n_s[i] = *(unsigned char *)s2;
		else
		{
			if (*(unsigned char *)s2)
				n_s[i++] = 47; // Backslash
			// Null
			//if (*(unsigned char *)s2 == 0)
				//n_s[i] = '0';
			// Backspace
			if (*(unsigned char *)s2 == 8)
				n_s[i] = 'b';
			// Horizontal Tab
			else if (*(unsigned char *)s2 == 9)
				n_s[i] = 't';
			// Newline
			else if (*(unsigned char *)s2 == 10)
				n_s[i] = 'n';
			// Vertical Tab
			else if (*(unsigned char *)s2 == 11)
				n_s[i] = 'v';
			// Formfeed Page Break
			else if (*(unsigned char *)s2 == 12)
				n_s[i] = 'f';
			// Carriage Return
			else if (*(unsigned char *)s2 == 13)
				n_s[i] = 'r';
		}
		if (i == count - 1)
			n_s[i] = '"';
		i++;
		s2++;
	}
	return (n_s);
}*/

// Print white spaces.
static int		ft_print_ws(size_t len)
{
	int		n;

	n = (int)len;
	while (len-- > 0)
		write(1, " ", 1);
	return (n);
}

/*static void		ft_print_ln(const char *s1, const char *s2, const char *comment, int com, int (*f)(const char *), int (*c)(const char *, const char *))
{
	char	*s;
	int		n;

	n = PRINT_WS;
	// Convert non printable characters
	s = ft_strconv(s2);
	ft_putstr(s1);
	// Print white spaces
	n -= ft_print_ws(n - (n - (15 - ft_strlen(s1))));
	ft_putstr(s);
	// Print white spaces
	if (com)
		n -= ft_print_ws(n - (ft_strlen(s1) + ft_strlen(s) + ft_strlen(comment)) - 2);
	else
		n -= ft_print_ws(n - (ft_strlen(s1) + ft_strlen(s)) - 2);
	// Put comment
	if (com)
		ft_putstr(comment);
	// Print white spaces
	ft_print_ws(2);
	// Apply atoi
	if (f)
		ft_putnbr(f(s2));
	// Apply strcmp
	else if (c)
		ft_putnbr(c(s2, comment));
	ft_putchar('\n');
}*/

// Print header for current file being tested.
static void		ft_print_h(const char *s)
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
	printf("\033[1;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n");
	int	fd = open(path, O_RDONLY);
	int	z = f(fd, line, buffer);
	printf("\033[1;34mBUFF_SIZE\033[0m..%d	\033[1;34mReading returned\033[0m..%d\n", buffer, z);
	close(fd);
	printf("\033[1;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n");
}

int		main(void)
{
	char	**line;
	size_t	len = 8 * 4; // Eight tests times amount of testfiles (four).

	if (!(line = (char **)ft_memalloc(sizeof(char *) * len)))
		return (0);
	while (len > 0)
		if (!(line[len-- - 1] = (char *)ft_memalloc(sizeof(char) * 10)))
			return (0);
	// test_1l
	ft_print_h("TEST ONE LINE");
	ft_print_gnl("test_1l", BUFF_SIZE_50, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE0, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE2, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE4, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE8, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE10, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE50, line, get_next_line);
	ft_print_gnl("test_1l", BUFF_SIZE100, line, get_next_line);
	// test_1l_nl
	ft_print_h("TEST ONE LINE WITH NEW LINE");
	ft_print_gnl("test_1l_nl", BUFF_SIZE_50, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE0, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE2, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE4, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE8, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE10, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE50, line, get_next_line);
	ft_print_gnl("test_1l_nl", BUFF_SIZE100, line, get_next_line);
	// test_2l
	ft_print_h("TEST TWO LINES");
	ft_print_gnl("test_2l", BUFF_SIZE_50, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE0, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE2, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE4, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE8, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE10, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE50, line, get_next_line);
	ft_print_gnl("test_2l", BUFF_SIZE100, line, get_next_line);
	// test_2l_nll
	ft_print_h("TEST TWO LINES WITH NEW LINE");
	ft_print_gnl("test_2l_nl", BUFF_SIZE_50, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE0, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE2, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE4, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE8, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE10, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE50, line, get_next_line);
	ft_print_gnl("test_2l_nl", BUFF_SIZE100, line, get_next_line);
	return (0);
}
