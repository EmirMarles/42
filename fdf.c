/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:51 by emarles           #+#    #+#             */
/*   Updated: 2025/02/23 15:04:49 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int    display(void);
static char *file_reading(char * file);


int main(int argc, char*argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return (0);
    }
    file_reading(argv[1]);
    display();
    return (0);
}

static char *file_reading(char *file)
{
    int fd;
    char *string;
    static char *buffer;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    string = get_next_line(fd);
    // printf("%s\n", string);
    free(string);
    close (fd);
    return (string);
}

static int    display()
{
    t_window  main;
    
    main.mlx_connection = mlx_init();
    if (main.mlx_connection == NULL)
        return(1);
    main.mlx_win = mlx_new_window(main.mlx_connection, WIDTH, HEIGHT, "this is running");
    if (NULL == main.mlx_win)
    {
        mlx_destroy_display(main.mlx_connection);
        free(main.mlx_connection);
        return (1);
    }
    main.img.img_ptr = mlx_new_image(main.mlx_connection, WIDTH, HEIGHT); //creating an image
    main.img.img_pixels_ptr = mlx_get_data_addr(main.img.img_ptr, &main.img.bits_per_pixel, &main.img.line_len, &main.img.endian); //memory info about the image
    
    mlx_key_hook(main.mlx_win, fdf_keyhook, &main); // why do we give a reference to the struct though?
    mlx_mouse_hook(main.mlx_win, fdf_mouse, &main);
    mlx_loop(main.mlx_connection);
    return (0);
}

