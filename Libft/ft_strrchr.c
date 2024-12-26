/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:07:46 by emarles           #+#    #+#             */
/*   Updated: 2024/12/26 17:15:05 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	last_seen;

	i = 0;
	last_seen = -1;
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
		{
			last_seen = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	if (last_seen == -1)
		return (NULL);
	return ((char *)&str[last_seen]);
}
