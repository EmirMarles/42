/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:07:20 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 16:34:28 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_string(const char *str, size_t max_len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < max_len)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = size_string(dst, destsize);
	src_len = size_string(src, SIZE_MAX);
	if (destsize == 0)
		return (src_len);
	if (destsize <= dst_len)
		return (destsize + src_len);
	i = 0;
	while (i < destsize - dst_len - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
