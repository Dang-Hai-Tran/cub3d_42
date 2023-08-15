/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:18:02 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 11:24:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	nb_rowcols(t_display *display, int fd)
{
	int		tmp_cols;
	char	c;

	display->map->rows = 0;
	display->map->cols = 0;
	tmp_cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (display->map->cols < tmp_cols)
			display->map->cols = tmp_cols;
		if (c == '\n')
		{
			display->map->rows++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
}

void	check_line(char *line, t_display *display)
{
	int	i;

	i = 0;
	while (line && line[i] && display)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
		{
			free(line);
			ft_error_fd("Unrecognized character in map file\n", 1, display);
		}
		i++;
	}
}

int	is_map_rectangle(t_display *display, int len2)
{
	int	len1;

	len1 = display->map->cols;
	if (len1 != len2)
		return (1);
	return (0);
}

int	is_adjacent_char_valid(char current, char neighbor)
{
	if (current == '0' && (neighbor == ' ' || neighbor == 0))
		return (0);
	if (neighbor != '0' && neighbor != '1' && neighbor != ' ' && neighbor != 0)
		return (0);
	return (1);
}

void	fill_adjacents(char *directions, t_map *map, int i, int j, int row_length)
{
	if (i > 0)
		directions[0] = map->pos[i - 1][j];
	if (i < map->rows - 1)
		directions[1] = map->pos[i + 1][j];
	if (j > 0)
		directions[2] = map->pos[i][j - 1];
	if (j < row_length - 1)
		directions[3] = map->pos[i][j + 1];
}

int is_adjacent_valid(t_map *map, int i, int j)
{
	char	*directions;
	int		row_length;
	int		d;

	directions = (char *)malloc(sizeof(char) * 4);
	if (!directions)
		return (0);
	row_length = ft_strlen(map->pos[i]);
	d = 0;
	while (d < 4)
	{
		directions[d] = 0;
		d++;
	}
	fill_adjacents(directions, map, i, j, row_length);
	d = 0;
	while (d < 4) 
	{
		if (!is_adjacent_char_valid(map->pos[i][j], directions[d]))
			return (0);
		d++;
	}
	free(directions);
	return (1);
}
