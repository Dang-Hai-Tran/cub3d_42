/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:04 by colin             #+#    #+#             */
/*   Updated: 2023/08/20 12:11:55 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(t_display *display, int fd)
{
	int	i;

	i = 0;
	nb_rowcols(display, fd);
	printf("rows: %d, cols: %d\n", display->mapinfo->rows, display->mapinfo->cols);
	display->mapinfo->pos = (char **)malloc(sizeof(char *) * (display->mapinfo->rows));
	if (!display->mapinfo->pos)
		ft_error_fd("Error on create map\n", 1, display);
	while (i < display->mapinfo->rows)
	{
		display->mapinfo->pos[i] = (char *)malloc(sizeof(char) * (display->map->rows + 1));
		if (!display->mapinfo->pos[i])
			ft_error_fd("Error on create map\n", 1, display);
		i++;
	}
	i = 0;
	display->mapinfo->exists = 1;
	while (i < display->mapinfo->rows)
	{
		display->mapinfo->pos[i] = (char *)malloc(sizeof(char)
				* (display->mapinfo->cols));
		if (!display->mapinfo->pos[i])
			ft_error_fd("Error on create map\n", 1, display);
		i++;
	}
}

int	is_map_walled(t_mapinfo *mapinfo, t_display *display)
{
	int		i;
	int		j;
	int		row_length;
	char	first_non_space_char;
	char	last_non_space_char;

	i = 0;
	while (i < mapinfo->rows)
	{
		// printf("map->pos[%d]: %s\n", i, map->pos[i]);
		row_length = ft_strlen(mapinfo->pos[i]);
		printf("row_length: %d\n", row_length);
		first_non_space_char = 0;
		last_non_space_char = 0;
		j = 0;
		while (j < row_length && !first_non_space_char) 
		{
			if (mapinfo->pos[i][j] != ' ')
				first_non_space_char = mapinfo->pos[i][j];
			j++;
		}
		j = row_length - 1;
		while (j >= 0 && !last_non_space_char) 
		{
			if (mapinfo->pos[i][j] != ' ')
				last_non_space_char = mapinfo->pos[i][j];
			j--;
		}
		if (first_non_space_char != '1' || last_non_space_char != '1') 
			ft_error_fd("Columns are not walled correctly!\n", 1, display);
		if (i == 0 || i == mapinfo->rows - 1)
			check_outer_wall(mapinfo, i, display);
		else 
		{
			j = 1;
			while (j < row_length - 1)
			{
				if (mapinfo->pos[i][j] == '0' && !is_adjacent_valid(mapinfo, i, j))
					ft_error_fd("0 is not surrounded correctly!\n", 1, display);
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	fill_map(t_display *display, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_fd("Error on open map file\n", 1, display);
	i = 0;
	j = -1;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line_length = ft_strlen(line);
		if (is_map_line(line) == 1)
		{
			while (++j < display->mapinfo->cols)
			{
				// printf("line: %s\n", line);
				// printf("i: %d, j: %d, cols: %d, line length: %u\n", i, j, display->map->cols, line_length);
				if (j < line_length)
				{
					// printf("i: %d, j: %d, cols: %d, line length: %u\n", i, j, display->map->cols, line_length);
					display->mapinfo->pos[i][j] = line[j];
				}
			}
			i++;
		}
		j = -1;
		free(line);
	}
	free(line);
}

t_display	*parse_map_file(t_display *display, char *filename)
{
	int				fd;
	char			*line;
	unsigned long	floor_rgb[3];
	unsigned long	ceiling_rgb[3];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line = skip_whitespace(line);
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(line, "NO", 2) == 0)
		{
			if (parse_texture_path(line, &display->texinfo->north) < 0)
			{
				perror("Error parsing north texture path");
				exit(1);
			}
			// printf("display->textureInfo->north: %s\n", display->textureInfo->north);
		}
		else if (ft_strncmp(line, "SO", 2) == 0) 
		{
			if (parse_texture_path(line, &display->texinfo->south) < 0)
			{
				perror("Error parsing south texture path");
				exit(1);
			}
			// printf("display->textureInfo->south: %s\n", display->textureInfo->south);
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			if (parse_texture_path(line, &display->texinfo->west) < 0)
			{
				perror("Error parsing west texture path");
				exit(1);
			}
			// printf("display->textureInfo->west: %s\n", display->textureInfo->west);
		}
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			if (parse_texture_path(line, &display->texinfo->east) < 0)
			{
				perror("Error parsing east texture path");
				exit(1);
			}
			// printf("display->textureInfo->east: %s\n", display->textureInfo->east);
		}
		else if (line[0] == 'F')
		{
			if (parse_rgb_color(line, floor_rgb) < 0)
			{
				perror("Error parsing floor RGB colors");
				exit(1);
			}
			display->texinfo->floor_rgb = floor_rgb;
			// printf("display->textureInfo->floor: %d, %d, %d\n", display->textureInfo->floor[0], display->textureInfo->floor[1], display->textureInfo->floor[2]);
		}
		else if (line[0] == 'C')
		{
			if (parse_rgb_color(line, ceiling_rgb) < 0)
			{
				perror("Error parsing ceiling RGB colors");
				exit(1);
			}
			display->texinfo->ceiling_rgb = ceiling_rgb;
			// printf("display->textureInfo->ceiling: %d, %d, %d\n", display->textureInfo->ceiling[0], display->textureInfo->ceiling[1], display->textureInfo->ceiling[2]);
		}
		else
		{
			// printf("Hello line: %s\n", line);
			fill_map(display, filename);
			// print_map(display);
			// printf("%s\n",display->map->pos[0]);
			// is_map_walled(display->map, display);
			break ;
		}
		free(line);
	}
	close(fd);
	return (display);
}
