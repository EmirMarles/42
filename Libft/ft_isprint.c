int ft_isprint(char a)
{
    if(a >= 32 && a <= 126)
    {
        return 1;
    }
    return 0;
}
/*int main(void)
{
    printf("%d", ft_isprint(' '));
    return (0);
}*/
