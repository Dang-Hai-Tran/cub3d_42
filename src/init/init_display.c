/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:23:02 by datran            #+#    #+#             */
/*   Updated: 2023/08/12 16:14:37 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_map(t_map *map)
{
	map->fd = 0;
	map->line_count = 0;
	map->path = NULL;
	map->file = NULL;
	map->height = 0;
	map->width = 0;
}

static void init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_x = 0;
	player->rotate = 0;
}

void	init_display(t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->win_height = WIN_HEIGHT;
	display->win_width = WIN_WIDTH;
	init_player(display->player);
	init_map(display->map);
	init_text(display->text);
	display->texture = NULL;
}

void	init_img_zero(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
