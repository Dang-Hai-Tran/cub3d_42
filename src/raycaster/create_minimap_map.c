/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:26:05 by datran            #+#    #+#             */
/*   Updated: 2023/09/07 13:49:21 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_minimap_map_line(t_minimap *mmap, t_display *dp, int y, int x)
{
	char		*mmap_line;

	mmap_line = ft_calloc(mmap->size + 1, sizeof(char));
	if (!mmap_line)
		free_exit(dp, err_msg("calloc minimap map line", FAIL));
	while (x < mmap->size && x < dp->mapinfo->width)
	{
		if (x + mmap->offset_x >= dp->mapinfo->width || y + mmap->offset_y \
		>= dp->mapinfo->height)
			mmap_line[x] = 0;
		else if (x + mmap->offset_x == (int)dp->player->pos_x && y \
		+ mmap->offset_y == (int)dp->player->pos_y)
			mmap_line[x] = 'P';
		else if (dp->map[y + mmap->offset_y][x + mmap->offset_x] == '1')
			mmap_line[x] = '1';
		else if (dp->map[y + mmap->offset_y][x + mmap->offset_x] == '0')
			mmap_line[x] = '0';
		else if (dp->map[y + mmap->offset_y][x + mmap->offset_x] == ' ')
			mmap_line[x] = ' ';
		else
			mmap_line[x] = 0;
		x++;
	}
	return (mmap_line);
}

char	**create_minimap_map(t_minimap *minimap, t_display *dp)
{
	char	**mmap;
	int		y;

	mmap = ft_calloc(minimap->size + 1, sizeof(char *));
	if (!mmap)
		free_exit(dp, err_msg("calloc minimap map", FAIL));
	y = 0;
	while (y < minimap->size && y < dp->mapinfo->height)
	{
		mmap[y] = get_minimap_map_line(minimap, dp, y, 0);
		y++;
	}
	mmap[minimap->size] = NULL;
	return (mmap);
}
