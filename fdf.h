/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:46 by emarles           #+#    #+#             */
/*   Updated: 2025/02/23 15:00:34 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

#define RED ff0000
#define	HEIGHT		720
#define WIDTH   1280
//structs
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct window
{
    void    *mlx_win;
    void    *mlx_connection;
    t_img   img; // for accumulatig the buffer of pixels for putting it later on 
	t_img	cube;
}   t_window;


int main(int argc, char*argv[]);

//event handling functions
int fdf_keyhook(int keycode, t_window *main);
int fdf_mouse(int button, int x, int y, void *param);

//putting image to the screen
void	my_pixel_put(t_img  *img, int x, int y, int color);
void	color_screen(t_window *data, int color);
void	draw_instructions(t_window * main);
void	put_cube(t_window * data);
void	color_cube(t_window *data, int color); // fills in the image for it then to be pushed.

# endif