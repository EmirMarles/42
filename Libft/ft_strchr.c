/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:07:15 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 17:21:01 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)search_str)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (search_str == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
