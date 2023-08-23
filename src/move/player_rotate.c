/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:56:52 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 16:35:16 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	player_rotate_right(t_display *display)
{
	t_player	*p;
	double		odir_x;
	double		oplane_x;

	p = display->player;
	odir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(ROTATE_SPEED) - p->dir_y * sin(ROTATE_SPEED);
	p->dir_y = odir_x * sin(ROTATE_SPEED) + p->dir_y * cos(ROTATE_SPEED);
	oplane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(ROTATE_SPEED) - p->plane_y * sin(ROTATE_SPEED);
	p->plane_y = oplane_x * sin(ROTATE_SPEED) + p->plane_y * cos(ROTATE_SPEED);
	return (1);
}

static int	player_rotate_left(t_display *display)
{
	t_player	*p;
	double		odir_x;
	double		oplane_x;

	p = display->player;
	odir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-ROTATE_SPEED) - p->dir_y * sin(-ROTATE_SPEED);
	p->dir_y = odir_x * sin(-ROTATE_SPEED) + p->dir_y * cos(-ROTATE_SPEED);
	oplane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-ROTATE_SPEED) - p->plane_y * sin(-ROTATE_SPEED);
	p->plane_y = oplane_x * sin(-ROTATE_SPEED) + p->plane_y * cos(-ROTATE_SPEED);
	return (1);
}

int	player_rotate(t_display *display)
{
	int		moved;

	moved = 0;
	if (display->player->rotate == 1)
		moved += player_rotate_right(display);
	if (display->player->rotate == -1)
		moved += player_rotate_left(display);
	return (moved);
}
