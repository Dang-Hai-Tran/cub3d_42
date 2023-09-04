/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:26:02 by datran            #+#    #+#             */
/*   Updated: 2023/09/04 15:30:57 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_minimap_offset(t_minimap *minimap, int map_size, int pos)
{
	if (pos > minimap->view_dist && map_size - pos > minimap->view_dist + 1)
		return (pos - minimap->view_dist);
	if (pos > minimap->view_dist && map_size - pos <= minimap->view_dist + 1)
		return (map_size - minimap->size);
	return (0);
}

void	init_minimap(t_minimap *minimap, t_display *display)
{
	minimap->map = NULL;
	minimap->image = &display->minimap;
	minimap->view_dist = MINIMAP_VIEW_DIST;
	minimap->size = 2 * minimap->view_dist + 1;
	minimap->tile_size = MINIMAP_DISPLAY_SIZE / minimap->size;
	minimap->offset_x = get_minimap_offset(minimap, \
	display->mapinfo->width, (int)display->player->pos_x);
	minimap->offset_y = get_minimap_offset(minimap, \
	display->mapinfo->height, (int)display->player->pos_y);
	minimap->hex_player = MINIMAP_HEX_PLAYER;
	minimap->hex_floor = MINIMAP_HEX_FLOOR;
	minimap->hex_wall = MINIMAP_HEX_WALL;
	minimap->hex_space = MINIMAP_HEX_SPACE;
	minimap->hex_border = MINIMAP_HEX_BORDER;
}
