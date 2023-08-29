/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inside_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:06:21 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map(t_map *map, char **tab)
{
	int	m;
	int	n;

	m = 0;
	while (m < map->height)
	{
		n = 0;
		while (n < map->width)
			n++;
		free(tab[m]);
		m++;
	}
	free(tab);
}

bool	ft_check_position_0_and_player(char **map, int m, int n)
{
	if (map[m - 1][n] == 0 || map[m - 1][n] == ' ')
		return (1);
	if (map[m + 1][n] == 0 || map[m + 1][n] == ' ')
		return (1);
	if (map[m][n - 1] == 0 || map[m][n - 1] == ' ')
		return (1);
	if (map[m][n + 1] == 0 || map[m][n + 1] == ' ')
		return (1);
	return (0);
}

bool	ft_check_inside_map2(t_data *data, char **tab)
{
	int	m;
	int	n;

	m = 0;
	while (m < data->m_map.height)
	{
		n = 0;
		while (n < data->m_map.width)
		{
			if (m > 0 && m < data->m_map.height - 1)
			{
				if (tab[m][n] == '0' || tab[m][n] == 'N' || tab[m][n] == 'S'
					|| tab[m][n] == 'W' || tab[m][n] == 'E')
				{
					if (ft_check_position_0_and_player(tab, m, n) == 1)
						return (ft_error(data,
								"map open", data->m_map.line_start + m + 1));
				}
			}
			n++;
		}
		m++;
	}
	return (0);
}

bool	ft_check_inside_map(t_data *data, char *file)
{
	int		i;
	bool	error;
	char	**map;

	map = (char **)malloc((data->m_map.height + 1) * sizeof(char *));
	if (!map)
		return (1);
	i = 0;
	while (i < data->m_map.height)
	{
		map[i] = (char *)malloc((data->m_map.width + 1) * sizeof(char));
		if (!map)
			return (1);
		ft_bzero(map[i], data->m_map.width);
		i++;
	}
	map[i] = 0;
	ft_set_value_to_map(&(data->m_map), file, map);
	error = ft_check_inside_map2(data, map);
	ft_free_map(&(data->m_map), map);
	return (error);
}
