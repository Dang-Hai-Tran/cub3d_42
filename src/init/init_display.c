/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:23:02 by datran            #+#    #+#             */
/*   Updated: 2023/08/29 17:59:08 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mapinfo(t_mapinfo *mapinfo, t_data *data)
{
	mapinfo->height = data->m_map.height;
	mapinfo->width = data->m_map.width;
}

static void	init_player_zero(t_player *player, t_data *data)
{
	if (data->m_player.p_char == 'N')
		player->dir = NORTH;
	if (data->m_player.p_char == 'S')
		player->dir = SOUTH;
	if (data->m_player.p_char =='E')
		player->dir = EAST;
	if (data->m_player.p_char == 'W')
		player->dir = WEST;
	player->pos_x = (double)data->m_player.p_col + 0.5;
	player->pos_y = (double)data->m_player.p_row + 0.5;
	data->map[data->m_player.p_row][data->m_player.p_col] = '0';
	player->has_moved = 0;
	player->move_x = 0;
	player->move_x = 0;
	player->rotate = 0;
}

static void	init_texinfo(t_texinfo *texinfo, t_data *data)
{
	texinfo->north = data->no_path;
	texinfo->south = data->so_path;
	texinfo->east = data->ea_path;
	texinfo->west = data->we_path;
	texinfo->rgb_floor = data->rgb_floor;
	texinfo->rgb_ceiling = data->rgb_ceiling;
	texinfo->hex_floor = convert_rgb_to_hex(texinfo->rgb_floor);
	texinfo->hex_ceiling = convert_rgb_to_hex(texinfo->rgb_ceiling);
	texinfo->size = TEX_SIZE;
	texinfo->step = 0;
	texinfo->pos = 0.0;
	texinfo->x = 0;
	texinfo->y = 0;
}

void	init_display(t_display *display, t_data *data)
{
	display->mlx = NULL;
	display->win = NULL;
	display->win_height = WIN_HEIGHT;
	display->win_width = WIN_WIDTH;
	display->player = ft_calloc(1, sizeof(t_player));
	if (!display->player)
		free_exit(display, err_msg("calloc player", 1));
	init_player_zero(display->player, data);
	init_player_dir(display->player);
	display->mapinfo = ft_calloc(1, sizeof(t_mapinfo));
	if (!display->mapinfo)
		free_exit(display, err_msg("calloc mapinfo", 1));
	init_mapinfo(display->mapinfo, data);
	display->texinfo = ft_calloc(1, sizeof(t_texinfo));
	if (!display->texinfo)
		free_exit(display, err_msg("calloc texinfo", 1));
	init_texinfo(display->texinfo, data);
	display->ray = ft_calloc(1, sizeof(t_ray));
	if (!display->ray)
		free_exit(display, err_msg("calloc ray", 1));
	display->map = data->map;
	display->texpixels = NULL;
	display->texbuffer = NULL;
}

void	init_img_zero(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
