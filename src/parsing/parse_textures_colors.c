/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:35:00 by codespace         #+#    #+#             */
/*   Updated: 2023/08/16 20:19:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture_path(char *line, char **path)
{
	line = skip_whitespace(line);
	*path = ft_strdup(line + 2);
	if (*path)
		return (0);
	return (-1);
}

int	parse_rgb_color(char *line, unsigned long *rgb)
{
	const char	*cursor;
	int			val;
	char		*end;
	int			i;

	cursor = line++;
	cursor = skip_whitespace(line);
	i = 0;
	while (i < 3)
	{
		val = strtol(cursor, &end, 10);
		if (end == cursor || val < 0 || val > 255)
			return (-1);
		rgb[i] = val;
		cursor = ft_strchr(cursor, ',');
		if (!cursor && i < 2)
			return (-1);
		cursor++;
		i++;
	}
	return (0);
}
