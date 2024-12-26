/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:05:26 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 17:49:11 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*sourc;
	unsigned char	*destn;

	sourc = (unsigned char *)src;
	destn = (unsigned char *)dest;
	i = 0;
	while (i < (int)n)
	{
		destn[i] = sourc[i];
		i++;
	}
	return (dest);
}
