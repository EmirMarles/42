/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:02:33 by emarles           #+#    #+#             */
/*   Updated: 2025/03/09 14:13:42 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_prelimenary_calculations(t_window * main);

void ft_calculate_position(t_window *main, size_t size) 
{
    int x;
    int y;
    int z;
    
    z = 1;

    ft_prelimenary_calculations(main);
    x = main->dot[0].x;
    y = main->dot[0].y;
    main->dot[0].x = x * cos(120) + y * cos(120 + 2) + z * cos(120 - 2); // formula for calculating x position
    main->dot[0].y = x * sin(120) + y * sin(120 + 2) + z * sin(120 - 2); // formula for calculating y position

    //what is z in this case? is it always gonna be the same?
    // main->line.x = (WIDTH/size);
    // main->line.y = HEIGHT/2;
    printf("the x position is %i\n", main->dot[0].x);
    printf("the y position is %i\n", main->dot[0].y);
    
    // second_pix = 
}

void ft_prelimenary_calculations(t_window * main) // prelimenary point in space relative to the amount of rows
{
    int grid_width;
    int grid_heigth;
    int x_pos;
    int y_pos;
    
    grid_width = (11 - 1) * 10; // hard coded for basictest.fdf but SHOULD be changed for different maps
    grid_heigth = (9 - 1)  * 10; // 10 is a PRELIMENARY spacing size between the dots placed; 

    x_pos = ((WIDTH - grid_width) / 2);
    y_pos = ((HEIGHT - grid_heigth) / 2);
    
    main->dot[0].x = x_pos;
    main->dot[0].y = y_pos;
}