#include "libft.h"

char    ft_toupper(char *s)
{
    int     i;
    char    j;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            j = s[i - 32];
            s[i] = j;
        }
        i++;
    }
    return (s);
}