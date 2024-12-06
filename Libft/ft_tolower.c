#include "libft.h"

char    ft_tolower(char *s)
{
    int     i;
    char    j;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            j = s[i + 32];
            s[i] = j;
        }
        i++;
    }
    return (s);
}