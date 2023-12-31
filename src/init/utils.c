/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:33:02 by datran            #+#    #+#             */
/*   Updated: 2023/09/07 13:39:08 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	convert_rgb_to_hex(int *rgb)
{
	int				r;
	int				g;
	int				b;
	unsigned long	ret;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	ret = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (ret);
}

int	*get_arr_rgb(int r, int g, int b)
{
	int		*rgb;

	rgb = ft_calloc(3, sizeof(int));
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}
