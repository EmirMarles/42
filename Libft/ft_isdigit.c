#include <stdio.h>

// converts to ASCII for check
char *ft_itoa(int k)
{
    int i;
    char    *c;
    i = 0;
    if (k < 0)
    {
        c[i] = "-";
    }
    else if(k <= 9)
    {
        ft_itoa(k / 10);
        ft_itoa(k % 10);
    }
    else
    {
        c[i] = 
    }

    return c;
}
int	ft_isdigit(int n)
{
    return n;
}
int main()
{ 
    printf("d", ft_isdigit(123));
    return 0;    
}
