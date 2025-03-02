/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:02:33 by emarles           #+#    #+#             */
/*   Updated: 2025/03/02 15:20:26 by emarles          ###   ########.fr       */
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
    if (ft_linechar(lines))
        size--;
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


void ft_calculate_position(t_window *main, size_t size)
{
    int x;
    int y;
    
    int first_pix;
    int second_pix;
    
    main->line.x = (WIDTH/size);
    main->line.y = HEIGHT/2;
    printf("the x position is %i\n", main->line.x);
    printf("the y position is %i\n", main->line.y);
    // second_pix = 
}
