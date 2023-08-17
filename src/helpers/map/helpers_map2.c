/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:23:46 by codespace         #+#    #+#             */
/*   Updated: 2023/08/17 00:57:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_outer_wall(t_map *map, int i, t_display *display)
{
	int	j;
	int	row_length;

	row_length = ft_strlen(map->pos[i]);
	j = 0;
	while (j < row_length)
	{
		if (map->pos[i][j] != '1' && map->pos[i][j] != ' ')
			ft_error_fd("Rows are not walled correctly!\n", 1, display);
		j++;
	}
}

int	is_adjacent_valid(t_map *map, int i, int j)
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

int is_map_line(char *line)
{
    int i;
	int found_one;
	
	i = 0;
	found_one = 0;
    while (line[i] != '\0') {
        if (line[i] != ' ' &&  line[i] != '1'
            && line[i] != '0' && line[i] != 'N'
            && line[i] != 'S' && line[i] != 'E' 
            && line[i] != 'W')
			{
            return (0);
        }
		if (line[i] == '1')
			found_one = 1;
        i++;
    }
    return (found_one);
}

void	print_map(t_display *display)
{
	int	i;

	i = 0;
	while (i < display->map->rows)
	{
		printf("display->map->pos[%d]: %s\n", i, display->map->pos[i]);
		i++;
	}
}