/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:04 by colin             #+#    #+#             */
/*   Updated: 2023/08/15 11:28:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(t_display *display, int fd)
{
	int	i;

	i = 0;
	nb_rowcols(display, fd);
	display->map->pos = (char **)malloc(sizeof(char *) * (display->map->rows));
	if (!display->map->pos)
		ft_error_fd("Error on create map\n", 1, display);
	display->map->exists = 1;
	while (i < display->map->rows)
	{
		display->map->pos[i] = (char *)malloc(sizeof(char)
				* (display->map->cols));
		if (!display->map->pos[i])
			ft_error_fd("Error on create map\n", 1, display);
		i++;
	}
}

int is_map_walled(t_map *map, t_display *display)
{
	int		i;
	int		j;
	int		row_length;
	char	first_non_space_char;
	char	last_non_space_char;

	i = 0;
	while (i < map->rows)
	{
		row_length = ft_strlen(map->pos[i]);
		first_non_space_char = 0;
		last_non_space_char = 0;
		j = 0;
		while (j < row_length && !first_non_space_char) 
		{
			if (map->pos[i][j] != ' ')
				first_non_space_char = map->pos[i][j];
			j++;
		}
		j = row_length - 1;
		while (j >= 0 && !last_non_space_char) 
		{
			if (map->pos[i][j] != ' ')
				last_non_space_char = map->pos[i][j];
			j--;
		}
		if (first_non_space_char != '1' || last_non_space_char != '1') 
			ft_error_fd("Columns are not walled correctly!\n", 1, display);
		if (i == 0 || i == map->rows - 1)
			check_outer_wall(map, i, display);
		else 
		{
			j = 1;
			while (j < row_length - 1)
			{
				if (map->pos[i][j] == '0' && !is_adjacent_valid(map, i, j))
					ft_error_fd("0 is not surrounded correctly!\n", 1, display);
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	load_map(t_display *display, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_fd("Error on open map file\n", 1, display);
	i = 0;
	j = -1;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		// check_line(line, display);
		// if (is_map_rectangle(display, ft_strlen(line)) == 1)
		// 	ft_error_fd("Map file is not rectangular.\n", 1, display);
		while (++j < display->map->cols)
		{
			display->map->pos[i][j] = line[j];
		}
		j = -1;
		i++;
		free(line);
	}
	free(line);
}
