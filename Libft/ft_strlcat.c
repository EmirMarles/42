#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    int i;
    int k;
    i = 0;
    k = ft_strlen(dst);
    while (src[i] != '\0' && i < size)
    {
        dst[k] = src[i];
        i++;
    }
    dst[k] = '\0';
    return (ft_strlen(dst));
}
