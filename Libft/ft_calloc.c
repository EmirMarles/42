/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:51:55 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 16:31:48 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			size_to_allocate;
	size_t			k;
	unsigned char	*p;

	if (!size || !nmemb)
		return (malloc(0));
	size_to_allocate = nmemb * size;
	if (nmemb != 0 && size_to_allocate / nmemb != size)
	{
		return (NULL);
	}
	ptr = malloc(size_to_allocate);
	if (ptr == NULL)
	{
		return (NULL);
	}
	p = (unsigned char *)ptr;
	k = 0;
	while (k < size_to_allocate)
	{
		p[k] = 0;
		k++;
	}
	return (ptr);
}
