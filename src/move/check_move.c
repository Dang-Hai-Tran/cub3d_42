/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:11:29 by datran            #+#    #+#             */
/*   Updated: 2023/08/15 09:32:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_pos_wall_collision(t_display *display, double pos_x, double pos_y)
{
	if (display->map[(int)pos_x][(int)pos_y] == '0')
		return (true);
	return (false);
}

static bool check_pos_in_map(t_display *display, double pos_x, double pos_y)
{
	if (pos_x < 0.25 || pos_x > display->mapinfo->width - 0.25)
		return (false);
	if (pos_y < 0.25 || pos_y > display->mapinfo->height - 0.25)
		return (false);
	return (true);
}

static bool check_pos_all(t_display *display, double pos_x, double pos_y)
{
	if (!BONUS && check_pos_in_map(display, pos_x, pos_y))
		return (true);
	if (BONUS && check_pos_in_map(display, pos_x, pos_y) && check_pos_wall_collision(display, pos_x, pos_y))
		return (true);
	return (false);
}

int	check_move(t_display *display, double npos_x, double npos_y)
{
	int		moved;

	moved = 0;
	if (check_pos_all(display, npos_x, display->player->pos_y))
	{
		display->player->pos_x = npos_x;
		moved = 1;
	}
	if (check_pos_all(display, display->player->pos_x, npos_y))
	{
		display->player->pos_y = npos_y;
		moved = 1;
	}
	return (moved);
}
