#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> 
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_isalpha(char *a);
int	ft_isdigit(int n);
int ft_isalnum (int a);
int ft_isascii(int a);
int ft_isprint(char a);
size_t ft_strlen(const char *s);
void *ft_memset(void *s, int c, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    ft_tolower(char *s);
char *strchr(const char *str, int search_str);



#endif