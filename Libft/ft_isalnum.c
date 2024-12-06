
int    ft_isalnum (int a)
{
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
    {
        return 1;
    }   
    else if (a >= '0' && a <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*int main(void)
{
    printf("%d", ft_isalnum('A'));
    return 0;
}*/