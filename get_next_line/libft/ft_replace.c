#include "libft.h"

char    *ft_replace(char *dst, const char *src, unsigned int left, unsigned int right)
{
    unsigned char   *d;
    unsigned char   *s;

    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (dst && src && (!left || !right))
    {
        if (right)
        {
            while (*d)
                d++;
            while (right++ < ft_strlen(dst))
                d--;
            while (*s)
                *d++ = (char)*s++;
        }
        else
        {
            while (left-- > 0)
                d++;
            while (*s)
                *d++ = (char)*s++;
        }
    }
    return (dst);
}