/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:23:02 by datran            #+#    #+#             */
/*   Updated: 2023/08/20 10:37:31 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->height = 0;
	mapinfo->width = 0;
}

static void init_player_zero(t_player *player)
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
	init_player_zero(display->player);
	init_mapinfo(display->mapinfo);
	init_texinfo(display->texinfo);
	display->map = NULL;
	display->textures_pixels = NULL;
	display->textures = NULL;
}

void	init_img_zero(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
