#include <stdio.h>
#include <stdlib.h>
static void ft_del(void *content, size_t content_size)
{
	printf("%zu\n", content_size);
	(void)content_size;
	printf("%zu\n", content_size);
	free(content);
	content = NULL;
}
int	main(void)
{
	ft_del(NULL, 3);
	return (0);
}
