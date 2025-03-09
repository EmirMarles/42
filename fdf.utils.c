/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:44:33 by emarles           #+#    #+#             */
/*   Updated: 2025/03/09 12:49:23 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char *ft_linechar(char **lines);

int ft_line_len(char *line) // when there is empty space at the end it calculates incorrectly
{
    char **lines;
    int i;
    int size;

    lines = ft_split(line, ' ');   
    
    size = 0;
    while (lines[size] != NULL)
        size++;
    // if (ft_linechar(lines))
    //     size--;
    free(lines);
    return (size);
}


static char *ft_linechar(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		if (ft_strchr(lines[i], '\n'))
			return (lines[i]);
		i++;
	}
	return (NULL);
}