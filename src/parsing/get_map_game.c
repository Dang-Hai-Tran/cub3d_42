/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:26:31 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 15:29:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map_arr(char **lines, int nb_lines, t_mapinfo *mapinfo)
{
	int		i;
	int		j;
	int		len;
	int		max_len;
	char	**map;

	map = ft_calloc(nb_lines - 6 + 1, sizeof(char *));
	i = 6;
	j = 0;
	max_len = 0;
	while (i < nb_lines)
	{
		map[j] = ft_strdup(lines[i]);
		len = ft_strlen(map[j]);
		if (len > max_len)
			max_len = len;
		i++;
		j++;
	}
	map[j] = NULL;
	mapinfo->width = max_len;
	mapinfo->height = j;
	return (map);
}

char	**fill_map_space_by_zero(char **map, int height, int width)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	new_map = ft_calloc(height + 1, sizeof(char *));
	while (i < height)
	{
		j = 0;
		new_map[i] = ft_calloc(width + 1, sizeof(char));
		while (j < width)
		{
			if ((j < (int)ft_strlen(map[i]) && ft_isspace(map[i][j])) || j >= (int)ft_strlen(map[i]))
				new_map[i][j] = '0';
			else
				new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	free_arr((void**)map);
	new_map[height] = NULL;
	return (new_map);
}

int	get_map_game(char **lines, int nb_lines, t_mapinfo *mapinfo, t_display *display)
{
	char	**map;

	map = get_map_arr(lines, nb_lines, mapinfo);
	map = fill_map_space_by_zero(map, mapinfo->height, mapinfo->width);
	if (check_map(map, display->player, mapinfo) == FAIL)
		return (FAIL);
	display->map = map;
	return (SUCCESS);
}
