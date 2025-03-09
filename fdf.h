/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:46 by emarles           #+#    #+#             */
/*   Updated: 2025/03/09 13:00:55 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <math.h>

#define	HEIGHT		720
#define WIDTH   1280
// # ifndef size
// #define size 0
//structs
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int	x;
	int	y;
	int	z;
	int		len_size;
}				t_img; // image data for displaying

// typedef struct matrix
// {
// 	t_img	x;
// 	t_img	y;
// }			t_matrix;

typedef struct window
{
    void    *mlx_win;
    void    *mlx_connection;
    t_img   img; // for accumulatig the buffer of pixels for putting it later on 
	t_img	cube;
	t_img	dot[0];
	// t_matrix matrix;
}   t_window;

typedef struct cube //cube struct
{
	int	x;
	int	y;
	void	*img_ptr;
	char	*imp_pixel_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
} cube;

int main(int argc, char*argv[]);

//event handling functions
int fdf_keyhook(int keycode, t_window *main);
int fdf_mouse(int button, int x, int y, void *param);

//putting image to the screen
void	my_pixel_put(t_img  *img, int x, int y, int color);
void	color_screen(t_window *data, int color);
void	draw_instructions(t_window * main);
void put_line(t_window *data);

// algorithm related functions
int ft_line_len(char *line);
void ft_calculate_position(t_window *main, size_t size);


# endif