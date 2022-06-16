#include "fdf.h"

void    ft_bzero(void *str, size_t n)
{
    char    *tmp;
    size_t  i;

    if (!n)
        return ;
    tmp = str;
    i = 0;
    while (i < n)
        *(tmp + i++) = 0;
}