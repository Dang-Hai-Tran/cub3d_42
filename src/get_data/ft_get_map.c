/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:42 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/29 17:09:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_infor_player(t_map *map, t_pplayer *player, char **tab)
{
	int	m;
	int	n;

	m = 0;
	while (m < map->height)
	{
		n = 0;
		while (n < map->width)
		{
			if (tab[m][n] == 0 || tab[m][n] == ' ')
				tab[m][n] = '0';
			if (m > 0 && m < map->height - 1)
			{
				if (tab[m][n] == 'N' || tab[m][n] == 'S'
					|| tab[m][n] == 'W' || tab[m][n] == 'E')
				{
					player->p_char = tab[m][n];
					player->p_col = n;
					player->p_row = m;
				}
			}
			n++;
		}
		m++;
	}
}

void	ft_get_map(t_data *data, char *file)
{
	int		i;
	char	**map;

	map = (char **)malloc((data->m_map.height + 1) * sizeof(char *));
	if (!map)
		return ;
	i = 0;
	while (i < data->m_map.height)
	{
		map[i] = (char *)malloc((data->m_map.width + 1) * sizeof(char));
		if (!map)
			return ;
		ft_bzero(map[i], data->m_map.width + 1);
		i++;
	}
	map[i] = 0;
	ft_set_value_to_map(&(data->m_map), file, map);
	ft_get_infor_player(&(data->m_map), &(data->m_player), map);
	data->map = map;
	// ft_print_information(data);
}
