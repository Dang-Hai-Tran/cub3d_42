/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 09:42:18 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 14:13:50 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_display *display, t_img *image, int x, \
int y)
{
	if (display->texpixels[y][x] > 0)
		set_image_pixel(image, x, y, display->texpixels[y][x]);
	else if (y < display->win_height / 2)
		set_image_pixel(image, x, y, display->texinfo->hex_ceiling);
	else if (y < display->win_height - 1)
		set_image_pixel(image, x, y, display->texinfo->hex_floor);
}

static void	render_frame(t_display *display)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(display, &image, display->win_width, display->win_height);
	y = 0;
	while (y < display->win_height)
	{
		x = 0;
		while (x < display->win_width)
		{
			set_frame_image_pixel(display, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(display->mlx, display->win, image.img, 0, 0);
	mlx_destroy_image(display->mlx, image.img);
}

static void	render_raycaster(t_display *display)
{
	init_texpixels(display);
	perform_raycaster(display);
	render_frame(display);
}

void	render_images(t_display *display)
{
	render_raycaster(display);
	// if (BONUS)
	// 	render_minimap(display);
}

int	render_display(t_display *display)
{
	display->player->has_moved += player_move(display);
	if (display->player->has_moved == 0)
		return (0);
	render_images(display);
	return (0);
}
