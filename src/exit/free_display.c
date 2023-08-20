/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:44:52 by datran            #+#    #+#             */
/*   Updated: 2023/08/19 16:04:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_arr(void **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

static void free_map_all(t_display *display)
{
	if (display->mapinfo->fd > 0)
		close(display->mapinfo->fd);
	if (display->mapinfo->path)
		free(display->mapinfo->path);
	if (display->map)
		free_arr(display->map);
}

static void free_texinfo(t_texinfo *texinfo)
{
	if (texinfo->north)
		free(texinfo->north);
	if (texinfo->south)
		free(texinfo->south);
	if (texinfo->east)
		free(texinfo->east);
	if (texinfo->west)
		free(texinfo->west);
	if (texinfo->floor)
		free(texinfo->floor);
	if (texinfo->ceiling)
		free(texinfo->ceiling);
}

void	free_display(t_display *display)
{
	if (display->textures)
		free_arr((void *)display->textures);
	if (display->textures_pixels)
		free_arr((void *)display->textures_pixels);
	free_texinfo(display->texinfo);
	free_map_all(display);
}
