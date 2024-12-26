/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:55:25 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 18:06:18 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		result_len;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	result_len = end - start + 1;
	if (result_len <= 0)
		return (ft_strdup(""));
	result = (char *)malloc(result_len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, &s1[start], result_len);
	result[result_len] = '\0';
	return (result);
}
