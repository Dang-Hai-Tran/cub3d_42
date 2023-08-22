/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:35:56 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 16:33:15 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_number_lines_map_file(char *path)
{
	int		fd;
	int		nb_lines;
	char	*line;

	nb_lines = 0;
	fd = open(path, O_RDONLY);
	line = ft_gnl(fd);
	while (line != NULL)
	{
		remove_backslash_end(line);
		if (*line)
			nb_lines++;
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	return (nb_lines);
}

static	char **get_lines_map_file(int fd, int nb_lines)
{
	char	**lines;
	char	*line;
	int		i;

	if (!nb_lines)
	{
		err_msg("Map file is empty", 1);
		return (NULL);
	}
	i = 0;
	lines = ft_calloc(nb_lines + 1, sizeof(char *));
	line = ft_gnl(fd);
	while (line != NULL)
	{
		remove_backslash_end(line);
		if (*line)
		{
			lines[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = ft_gnl(fd);
	}
	lines[i] = NULL;
	return (lines);
}

int	get_mapinfo(int fd, t_mapinfo *mapinfo)
{
	mapinfo->nb_lines = get_number_lines_map_file(mapinfo->path);
	mapinfo->lines = get_lines_map_file(fd, mapinfo->nb_lines);
	if (!mapinfo->lines)
		return (FAIL);
	return (SUCCESS);
}
