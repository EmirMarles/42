/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:37 by emarles           #+#    #+#             */
/*   Updated: 2025/03/09 14:12:12 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void fdf_close(t_window *main);

int fdf_keyhook(int keycode, t_window *main)
{
    printf("key '%i' has been pressed\n", keycode);
    if (keycode == XK_Escape)
        fdf_close(main);
    if (keycode == XK_w)
    {
        color_screen(main, 0xff0000);    
        mlx_put_image_to_window(main->mlx_connection, main->mlx_win,main->img.img_ptr,0, 0); // pushes the image to the screen
        draw_instructions(main);
    }
    else if (keycode == XK_s)
    {
        ft_calculate_position(main, 10);
        put_line(main);
        // here while loop also
        mlx_put_image_to_window(main->mlx_connection, main->mlx_win, main->dot[0].img_ptr, main->dot[0].x, main->dot[0].y);
    }
    return (0);
}

int fdf_mouse(int button, int x, int y, void *param)
{
    t_window *main = (t_window *)param;
    
    printf("the mouse key '%i' has been pressed\n", button);
    if (button == 1)
        fdf_close(main);
    return (0);
}

static void fdf_close(t_window *win)
{
    t_window *main = (t_window *)(win); 
    
    mlx_loop_end(main->mlx_connection);
    mlx_destroy_window(main->mlx_connection, main->mlx_win);
    mlx_destroy_display(main->mlx_connection);
    free(main->mlx_connection);
    exit(0);
}
