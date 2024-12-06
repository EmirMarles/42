#include "libft.h"

void bzero(void *s, size_t len)
{
    int i;
    i = 0;
    
    while(s[i] != len)
    {
        i++;
    }
}