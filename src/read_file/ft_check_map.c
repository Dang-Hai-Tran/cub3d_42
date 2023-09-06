/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:44:01 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_character_map(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ')
		{
			printf("Error: [%d] cannot be determined !\n", data->m_line.id_line);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_get_size_map(t_data *data, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (data->m_map.width < len)
	{
		if (str[len - 1] == '\n')
			data->m_map.width = len - 1;
		else
			data->m_map.width = len;
	}
	data->m_map.height++;
	data->m_map.line_end = data->m_line.id_line;
}

bool	ft_check_empty_line(t_data *data)
{
	if (data->m_line.id_line_new_line != 0)
	{
		printf("Error: [%d] empty line on map !\n",
			data->m_line.id_line_new_line);
		return (1);
	}
	return (0);
}

bool	ft_check_map(t_data *data, char *str)
{
	if (ft_check_character_map(data, str) == 1)
		return (1);
	if (data->m_map.find_map == false)
	{
		data->m_map.line_start = data->m_line.id_line;
		data->m_map.find_map = true;
	}
	if (ft_check_empty_line(data) == 1)
		return (1);
	ft_get_size_map(data, str);
	if (ft_check_nomber_player(data, str) == 1)
		return (1);
	if (ft_check_end_space(data, str) == 1)
		return (1);
	return (0);
}
