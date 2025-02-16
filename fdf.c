/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:51 by emarles           #+#    #+#             */
/*   Updated: 2025/02/16 17:28:12 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




int main(int argc, char*argv[])
{
    t_window  main;
    char *string;
    int fd;

    fd = open(argv[1], O_RDONLY);
    main.mlx_connection = mlx_init();
    if (main.mlx_connection == NULL)
        return(1);
    main.mlx_win = mlx_new_window(main.mlx_connection, 600, 800, "this is running");
    if (NULL == main.mlx_win)
    {
        mlx_destroy_display(main.mlx_connection);
        free(main.mlx_connection);
        return (1);
    }
    while (1)
    {
        string = get_next_line(fd);
        printf("%s\n", string);
        free(string);
    }   
    // printf("%s\n", string);
     
    mlx_key_hook(main.mlx_win, close_win, &main); // why do we give a reference to the struct though?
    mlx_mouse_hook(main.mlx_win, mouse_function, &main); //mouse handling
    mlx_loop(main.mlx_connection);
    // mlx_destroy_window(main.mlx_connection, main.mlx_win);
    // mlx_destroy_display(main.mlx_connection);
    // free(main.mlx_connection);
    close(fd);
    return (0);
}