/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_sides.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:13:50 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 11:07:37 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_wall_top(char **map, int height, int width)
{
	int		i;
	int		j;

	j = 0;
	while (j < width)
	{
		i = 0;
		while (i < height && map[i][j] != '1')
			i++;
		if (i == height)
			return (err_msg("top wall invalid", FAIL));
		j++;
	}
	return (SUCCESS);
}

static int	check_wall_bottom(char **map, int height, int width)
{
	int		i;
	int		j;

	j = 0;
	while (j < width)
	{
		i = height - 1;
		while (i >= 0 && map[i][j] != '1')
			i--;
		if (i == -1)
			return (err_msg("bottom wall invalid", FAIL));
		j++;
	}
	return (SUCCESS);
}

static int	check_wall_left(char **map, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width && map[i][j] != '1')
			j++;
		if (j == width)
			return ("left wall invalid", FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	check_wall_right(char **map, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = width;
		while (j >= 0 && map[i][j] != '1')
			j--;
		if (j == -1)
			return ("right wall invalid", FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_map_sides(char **map, int height, int width)
{
	if (check_wall_top(map, height, width) == FAIL)
		return (FAIL);
	if (check_wall_bottom(map, height, width) == FAIL)
		return (FAIL);
	if (check_wall_left(map, height, width) == FAIL)
		return (FAIL);
	if (check_wall_right(map, height, width) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
