#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    int i;
    int k;
    i = 0;
    k = ft_strlen(dst);
    if (size <= k)
    {
        return size + ft_strlen(src);
    }
    while (i < size - 1 && src[i] != '\0')
    {
        dst[k] = src[i];
        i++;
    }
    dst[k + i]  = '\0';
    return (k + ft_strlen(src));
}
