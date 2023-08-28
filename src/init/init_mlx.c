/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:38:00 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 14:07:01 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_display *display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		free_exit(display, err_msg("mlx init", 1));
	display->win = mlx_new_window(display->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!display->win)
		free_exit(display, err_msg("mlx new window", 1));
	if (BONUS)
		mlx_mouse_move(display->mlx, display->win, \
		display->win_width / 2, display->win_height / 2);
}

void	init_texture(t_display *display, t_img *image, char *path)
{
	init_img_zero(image);
	image->img = mlx_xpm_file_to_image(display->mlx, \
	path, &display->texinfo->size, &display->texinfo->size);
	if (!image->img)
		free_exit(display, err_msg("mlx xpm file to image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, \
	&image->pixel_bits, &image->size_line, &image->endian);
}

void	init_img(t_display *display, t_img *image, int width, int height)
{
	init_img_zero(image);
	image->img = mlx_new_image(display->mlx, width, height);
	if (!image->img)
		free_exit(display, err_msg("mlx new image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, \
	&image->pixel_bits, &image->size_line, &image->endian);
}
