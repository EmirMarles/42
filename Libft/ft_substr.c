/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:52:23 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 16:35:11 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	size;

	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL || s == NULL)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (start > size)
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
