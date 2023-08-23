/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:53:39 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 10:02:05 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_texinfo_path(char **lines, t_dir dir)
{
	int		i;
	char	*path;
	char	*tmp_char_dir;

	i = 0;
	path = NULL;
	while (i < 6)
	{
		tmp_char_dir = ft_substr(lines[i], 0, 2);
		if (!ft_strncmp(tmp_char_dir, "NO", 3) && dir == NORTH)
			path = remove_white_space(lines[i] + 2);
		if (!ft_strncmp(tmp_char_dir, "SO", 3) && dir == SOUTH)
			path = remove_white_space(lines[i] + 2);
		if (!ft_strncmp(tmp_char_dir, "EA", 3) && dir == EAST)
			path = remove_white_space(lines[i] + 2);
		if (!ft_strncmp(tmp_char_dir, "WE", 3) && dir == WEST)
			path = remove_white_space(lines[i] + 2);
		free(tmp_char_dir);
		i++;
	}
	return (path);
}

static char	*get_rgb_char(char **lines, t_dir dir)
{
	int		i;
	char	*tmp_char_dir;
	char	*rgb;

	i = 0;
	rgb = NULL;
	while (i < 6)
	{
		tmp_char_dir = ft_substr(lines[i], 0, 1);
		if (!ft_strncmp(tmp_char_dir, "F", 2) && dir == FLOOR)
			rgb = remove_white_space(lines[i] + 1);
		if (!ft_strncmp(tmp_char_dir, "C", 2) && dir == CEILING)
			rgb = remove_white_space(lines[i] + 1);
		free(tmp_char_dir);
		i++;
	}
	return (rgb);
}

static int	*get_rgb_arr(char *rgb)
{
	int		begin;
	int		end;
	int		i;
	char	*tmp;
	int		*rgb_arr;

	i = 0;
	rgb_arr = ft_calloc(3, sizeof(int));
	if (!rgb_arr)
		return (NULL);
	end = 0;
	while (end < (int)ft_strlen(rgb))
	{
		begin = end;
		while (rgb[end] != 0 && rgb[end] != ',')
			end++;
		end++;
		tmp = ft_substr(rgb, begin, end - begin - 1);
		if (!str_contain_only_digits(tmp))
		{
			free(tmp);
			free(rgb);
			return (NULL);
		}
		rgb_arr[i] = ft_atoi(tmp);
		free(tmp);
		i++;
	}
	free(rgb);
	return (rgb_arr);
}

int	get_texinfo(char **lines, t_texinfo *texinfo)
{
	texinfo->north = get_texinfo_path(lines, NORTH);
	texinfo->south = get_texinfo_path(lines, SOUTH);
	texinfo->east = get_texinfo_path(lines, EAST);
	texinfo->west = get_texinfo_path(lines, WEST);
	if (!texinfo->north || !texinfo->south || !texinfo->east || !texinfo->west)
		return (err_msg("texture path invalid", 1));
	if (!arg_is_valid_ext(texinfo->north, ".xpm") || !arg_is_valid_ext(texinfo->south, ".xpm") || !arg_is_valid_ext(texinfo->east, ".xpm") || !arg_is_valid_ext(texinfo->west, ".xpm"))
		return (FAIL);
	texinfo->rgb_floor = get_rgb_arr(get_rgb_char(lines, FLOOR));
	texinfo->rgb_ceiling = get_rgb_arr(get_rgb_char(lines, CEILING));
	if (!check_rgb_value(texinfo->rgb_floor) || !check_rgb_value(texinfo->rgb_ceiling))
		return (err_msg("texture rgb value invalid", 1));
	texinfo->hex_floor = rgb_to_hex(texinfo->rgb_floor);
	texinfo->hex_ceiling = rgb_to_hex(texinfo->rgb_ceiling);
	return (SUCCESS);
}
