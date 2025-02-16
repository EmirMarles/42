/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:46 by emarles           #+#    #+#             */
/*   Updated: 2025/02/16 15:23:17 by emarles          ###   ########.fr       */
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
//structs
typedef struct window
{
    void    *mlx_win;
    void    *mlx_connection;
}   t_window;


int main(int argc, char*argv[]);

//event handling functions
int close_win(int keycode, t_window *main);
int mouse_function(int button, int x, int y, void *param);

# endif