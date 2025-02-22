/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:18:26 by emarles           #+#    #+#             */
/*   Updated: 2025/02/22 16:44:00 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img  *img, int x, int y, int color)
{
	int	offset;

	//Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_window *data, int color)
{
	for (int y = 0; y < HEIGHT; ++y)	
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			my_pixel_put(&data->img,
						x, 
						y, 
						color);
		}
	}
}