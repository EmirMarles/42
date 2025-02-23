/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:18:26 by emarles           #+#    #+#             */
/*   Updated: 2025/02/23 15:03:40 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_instructions(t_window * main) 
{
	mlx_string_put(main->mlx_connection, main->mlx_win, 15, WIDTH - 1200, 0x003366FF, "The first line"); 
    mlx_string_put(main->mlx_connection, main->mlx_win, 15, WIDTH - 1180, 0x003366FF, "The second line");
    mlx_string_put(main->mlx_connection, main->mlx_win, 15, WIDTH - 1160, 0x003366FF, "The third line");
}

void	my_pixel_put(t_img  *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_window *data, int color) // fills in the image for it then to be pushed.
{
	for (int y = 0; y < HEIGHT; ++y)	
	{
		for (int x = 0; x < WIDTH; ++x) //fills in each individual pixel with my_pixel_put
		{
			my_pixel_put(&data->img,
						x, 
						y, 
						color);
		}
	}
}

// void	put_cube(t_window * data)
// {
// 	int	color;

// 	color = 0x00006699;

// 	for (int y = 0; y < 10; ++y)
// 	{
// 		for (int x = 0; x < 10; ++x)
// 		{
// 			my_pixel_put(&data->cube, x , y , color);
// 		}
// 	}
	
// }
