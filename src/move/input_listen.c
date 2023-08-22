/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_listen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:24:24 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 11:21:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int key_press_handler(int key, t_display *display)
{
	if (key == XK_Escape)
		free_exit(display, 0);
	if (key == XK_Left)
		display->player->rotate = -1;
	if (key == XK_Right)
		display->player->rotate = 1;
	if (key == XK_w)
		display->player->move_y = 1;
	if (key == XK_s)
		display->player->move_y = -1;
	if (key == XK_a)
		display->player->move_x = -1;
	if (key == XK_d)
		display->player->move_x = 1;
	return (0);
}

static int key_release_handler(int key, t_display *display)
{
	if (key == XK_Escape)
		free_exit(display, 0);
	if (key == XK_Left && display->player->rotate == -1)
		display->player->rotate = 0;
	if (key == XK_Right && display->player->rotate == 1)
		display->player->rotate = 0;
	if (key == XK_w && display->player->move_y == 1)
		display->player->move_y = 0;
	if (key == XK_s && display->player->move_y == -1)
		display->player->move_y = 0;
	if (key == XK_a && display->player->move_x == -1)
		display->player->move_x = 0;
	if (key == XK_d && display->player->move_x == 1)
		display->player->move_x = 0;
	return (0);
}

static int	mouse_motion_handler(int x, int y, t_display *display)
{
	static int	old_x = WIN_WIDTH / 2;

	(void)y;
	if (x == old_x)
		return (0);
	else if (x < old_x)
	{
		display->player->rotate = -1;
		display->player->has_moved += player_rotate(display);
	}
	else if (x > old_x)
	{
		display->player->rotate = 1;
		display->player->has_moved += player_rotate(display);
	}
	old_x = x;
	return (0);
}

void	input_listen(t_display *display)
{
	mlx_hook(display->win, ClientMessage, NoEventMask, quit_cub3d, display);
	mlx_hook(display->win, KeyPress, KeyPressMask, key_press_handler, display);
	mlx_hook(display->win, KeyRelease, KeyReleaseMask, key_release_handler, display);
	if (BONUS)
		mlx_hook(display->win, MotionNotify, PointerMotionMask,
			mouse_motion_handler, display);
}
