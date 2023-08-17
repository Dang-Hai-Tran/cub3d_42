/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:18:02 by codespace         #+#    #+#             */
/*   Updated: 2023/08/17 01:15:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void nb_rowcols(t_display *display, int fd)
{
	int i;
	char *line;

	display->map->rows = 0;
	display->map->cols = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		if (is_map_line(line) == 1) {
			printf("line: %s\n", line);
			while (line[i] != '\0')
				i++;
			display->map->rows++;
		}
		if (display->map->cols < i)
			display->map->cols = i;
		free(line);  // Free the memory allocated by get_next_line
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
