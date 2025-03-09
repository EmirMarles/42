/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:51 by emarles           #+#    #+#             */
/*   Updated: 2025/03/09 14:07:08 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int    ft_display(char *file);
static int file_reading(char * file);

int main(int argc, char*argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return (0);
    }
    ft_display(argv[1]);
    return (0);
}

static int file_reading(char *file)
{
    int fd;
    char *string;
    static char *buffer;
    int size;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    string = get_next_line(fd);
    size = ft_line_len(string);
    printf("%s\n", string);
    printf("the size of the %i\n", size);
    free(string);
    close (fd);
    return (size);
}

static int    ft_display(char *file)
{
    t_window  main; // everything should be saved here for manipulating the data
    int size;
    int beginning;
    
    beginning = 0;
    size = file_reading(file);
    main.dot[size]; // array of dots
    
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
    //
    // while loop here to create DOT pointers and get data of these DOT pointers
    while (beginning < size)
    {
        main.dot[beginning].img_ptr = mlx_new_image(main.mlx_connection, 1, 1);
        main.dot[beginning].img_pixels_ptr = mlx_get_data_addr(main.dot[beginning].img_ptr, &main.dot[beginning].bits_per_pixel, &main.dot[beginning].line_len, &main.dot[beginning].endian); // creating a dot
        beginning++;
    }// ft_render(main);
    mlx_key_hook(main.mlx_win, fdf_keyhook, &main);
    mlx_mouse_hook(main.mlx_win, fdf_mouse, &main);
    mlx_loop(main.mlx_connection);
    return (0);
}
// separate function for rendering

// so we need a struct for object on the screen separate from the main image pointer
