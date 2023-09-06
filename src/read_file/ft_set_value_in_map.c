/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_value_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:10:14 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 18:33:44 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_value_to_map2(char **tab, int m, char *str)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != '\n')
	{
		tab[m][n] = str[n];
		n++;
	}
}

void	ft_set_value_to_map(t_map *map, char *file, char **tab)
{
	int		fd;
	int		i;
	int		id_line;
	char	*line;

	fd = open(file, O_RDONLY);
	id_line = 0;
	i = 0;
	while (42)
	{
		id_line++;
		line = ft_gnl_bonus(fd);
		if (!line)
			break ;
		if (id_line >= map->line_start
			&& id_line <= map->line_end)
		{
			ft_set_value_to_map2(tab, i, line);
			i++;
		}
		free(line);
	}
	close(fd);
}
