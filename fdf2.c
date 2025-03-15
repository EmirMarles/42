/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:12:01 by emarles           #+#    #+#             */
/*   Updated: 2025/03/15 15:10:20 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int    file_reading(char *file, grid *grid);

int main(int  argc, char*argv[])
{
    grid    grid;
    if (argc < 2)
    {
        printf("not enought arguments\n");
        return (0);
    }
    file_reading(argv[1], &grid);
    return (0);
}
int    file_reading(char *file, grid *grid)
{
    int fd;
    char *string;

    fd = open(file, O_RDONLY);
    
    if (fd < 0)
        return (1);
    string = get_next_line(fd); //getting the line complicates the determination of the HEIGHT size
    grid->lentgh = grid_lentgh(string); // determines the LENGTH of the array
    grid->height = grid_height(fd); //determines to HEIGHT of the array;
    printf("the lentgth of the grid is %i\n", grid->lentgh);
    printf("the height of the grid is %i\n", grid->height);
    free(string);
    close(fd);
    return (0);
}