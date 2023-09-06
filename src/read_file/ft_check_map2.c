/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:00:40 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:45:24 by datran           ###   ########.fr       */
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
	if (n == 0)
		return (1);
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

bool	ft_check_open(t_data *data, char **tab, int m, int n)
{
	if (data->m_map.line_start + m == data->m_map.line_start
		|| data->m_map.line_start + m == data->m_map.line_end
		|| ft_check_position_0_and_player(tab, m, n) == 1)
	{
		data->error = 1;
		if (tab[m][n] != '0')
			printf("Error: [%d] Player is not surrounded by walls !\n",
				data->m_map.line_start + m);
		else
			printf("Error: [%d] Floor is not surrounded by walls !\n",
				data->m_map.line_start + m);
		return (1);
	}
	return (0);
}

bool	ft_check_inside_map(t_data *data, char **tab)
{
	int	m;
	int	n;

	m = 0;
	while (m < data->m_map.height)
	{
		n = 0;
		while (n < data->m_map.width)
		{
			if (tab[m][n] == '0' || tab[m][n] == 'N' || tab[m][n] == 'S'
				|| tab[m][n] == 'W' || tab[m][n] == 'E')
			{
				if (ft_check_open(data, tab, m, n) == 1)
					return (1);
			}
			n++;
		}
		m++;
	}
	return (0);
}

bool	ft_check_map_open(t_data *data, char *file)
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
		ft_bzero(map[i], data->m_map.width + 1);
		i++;
	}
	map[i] = 0;
	ft_set_value_to_map(&(data->m_map), file, map);
	error = ft_check_inside_map(data, map);
	if (error == 0)
		error = ft_find_player(data);
	ft_free_map(&(data->m_map), map);
	return (error);
}
