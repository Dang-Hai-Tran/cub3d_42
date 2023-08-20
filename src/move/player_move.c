/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:08:33 by datran            #+#    #+#             */
/*   Updated: 2023/08/20 10:31:45 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int player_move_forward(t_display *display)
{
	double		npos_x;
	double		npos_y;
	
	npos_x = display->player->pos_x + display->player->dir_x * MOVE_SPEED;
	npos_y = display->player->pos_y + display->player->dir_y * MOVE_SPEED;
	return (check_move(display, npos_x, npos_y));
}

static int player_move_backward(t_display *display)
{
	double		npos_x;
	double		npos_y;
	
	npos_x = display->player->pos_x - display->player->dir_x * MOVE_SPEED;
	npos_y = display->player->pos_y - display->player->dir_y * MOVE_SPEED;
	return (check_move(display, npos_x, npos_y));
}

static int	player_move_right(t_display *display)
{
	double		npos_x;
	double		npos_y;

	npos_x = display->player->pos_x + display->player->dir_y * MOVE_SPEED;
	npos_y = display->player->pos_y - display->player->dir_x * MOVE_SPEED;
	return (check_move(display, npos_x, npos_y));
}

static int	player_move_left(t_display *display)
{
	double		npos_x;
	double		npos_y;

	npos_x = display->player->pos_x - display->player->dir_y * MOVE_SPEED;
	npos_y = display->player->pos_y + display->player->dir_x * MOVE_SPEED;
	return (check_move(display, npos_x, npos_y));
}

int	player_move(t_display *display)
{
	int		moved;
	
	moved = 0;
	if (display->player->move_x == 1)
		moved += player_move_right(display);
	if (display->player->move_x == -1)
		moved += player_move_left(display);
	if (display->player->move_y == 1)
		moved += player_move_forward(display);
	if (display->player->move_y == -1)
		moved += player_move_backward(display);
	if (display->player->rotate != 0)
		moved += player_rotate(display);
	return (moved);
}
