/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texbuffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:57 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 14:08:00 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_display *display, char *path)
{
	t_img	image;
	int		*buf;
	int		x;
	int		y;
	int		tex_size;

	init_texture(display, &image, path);
	buf = ft_calloc(display->texinfo->size * display->texinfo->size, \
	sizeof(int));
	if (!buf)
		free_exit(display, err_msg("calloc buf xpm to img", 1));
	y = 0;
	tex_size = display->texinfo->size;
	while (y < tex_size)
	{
		x = 0;
		while (x < tex_size)
		{
			buf[y * tex_size + x] = image.addr[y * tex_size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(display->mlx, image.img);
	return (buf);
}

void	init_texbuffer(t_display *display)
{
	display->texbuffer = ft_calloc(5, sizeof(int *));
	if (!display->texbuffer)
		free_exit(display, err_msg("malloc", 1));
	display->texbuffer[NORTH] = xpm_to_img(display, display->texinfo->north);
	display->texbuffer[SOUTH] = xpm_to_img(display, display->texinfo->south);
	display->texbuffer[EAST] = xpm_to_img(display, display->texinfo->east);
	display->texbuffer[WEST] = xpm_to_img(display, display->texinfo->west);
	display->texbuffer[4] = NULL;
}
