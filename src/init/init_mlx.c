/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:38:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/16 10:55:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_gamewindow(t_display *display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		ft_error_fd("Error on mlx init in init gamewindow\n", 1, display);
	display->win = mlx_new_window(display->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!display->win)
		ft_error_fd("Error on mlx new window in init gamewindow\n", 1, display);
	if (BONUS)
		mlx_mouse_move(display->mlx, display->win, display->win_width / 2, display->win_height / 2);
}

void	init_texture_struct(t_display *display, t_img *image, char *path)
{
	init_img_zero_struct(image);
	image->img = mlx_xpm_file_to_image(display->mlx, path, &display->textureInfo->size, &display->textureInfo->size);
	if (!image->img)
		free_exit(display, err_msg("mlx xpm file to image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
}

void	init_img(t_display *display, t_img *image, int width, int height)
{
	init_img_zero_struct(image);
	image->img = mlx_new_image(display->mlx, width, height);
	if (!image->img)
		free_exit(display, err_msg("mlx new image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
}
