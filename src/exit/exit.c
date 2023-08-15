/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:40:46 by datran            #+#    #+#             */
/*   Updated: 2023/08/12 15:44:32 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_display(t_display *display)
{
    if (display->map)
        free(display->map);
    if (display->player)
        free(display->player);
    if (display->ray)
        free(display->ray);
    if (display->text)
        free(display->text);
    if (display->map_arr_str)
        free(display->map_arr_str);
    if (display->textures)
        free(display->textures);
    if (display->textures_pixels)
        free(display->textures_pixels);
    // if (display)
    //     free(display);
}

void	free_exit(t_display *display, int exit_code)
{
	if (!display)
		exit(exit_code);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
	{
		mlx_destroy_display(display->mlx);
		mlx_loop_end(display->mlx);
        if (display->mlx)
		    free(display->mlx);
	}
	free_display(display);
	exit(exit_code);
}
