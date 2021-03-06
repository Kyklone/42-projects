/*
 *
 *	TEST HEADER FILE FOR MULTIPLE BUFF_SIZES
 *	  AND EXTERNAL TEST FUNCTIONS FOR MAIN
 *
 */

#ifndef GET_NEXT_LINE_TEST_H

# define GET_NEXT_LINE_TEST_H

# define			BUFF_SIZE0		0
# define			BUFF_SIZE1		1
# define			BUFF_SIZE2		2
# define			BUFF_SIZE_50	3
# define			BUFF_SIZE4		4
# define			BUFF_SIZE5		5
# define			BUFF_SIZE6		6
# define			BUFF_SIZE7		7
# define			BUFF_SIZE8		8
# define			BUFF_SIZE9		9
# define			BUFF_SIZE10		10
# define			BUFF_SIZE50		50
# define			BUFF_SIZE100	100
# define			BUFF_SIZE500	500
# define			BUFF_SIZE1000	1000
# define			test1			7
# define			test2			7
# define			test3			4
# define			test4			4
# define			test5			18

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line, size_t BUFF);
int		ft_print_ws(size_t len);
void	ft_print_h(const char *s);
void	ft_print_gnl(const char *path, int buffer, char **line, int (*f)(int, char **, size_t), int linelen);

#endif
