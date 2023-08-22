/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_sides.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:13:50 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 22:59:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_top_or_bottom(char **map, int i, int j)
{
	if (!map || !map[i] || !map[i][j])
		return (FAIL);
	while (map[i][j])
	{
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (FAIL);
		j++;
	}
	return (SUCCESS);
}

int	check_map_sides(t_mapinfo *mapinfo, char **map)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map, 0, 0) == FAIL)
		return (err_msg("top of map is invalid", FAIL));
	i = 1;
	while (i < (mapinfo->height - 1))
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (err_msg("left of map is invalid", FAIL));
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			return (err_msg("right of map is invalid", FAIL));
		i++;
	}
	if (check_top_or_bottom(map, i, 0) == FAIL)
		return (err_msg("bottom of map is invalid", FAIL));
	return (SUCCESS);
}
