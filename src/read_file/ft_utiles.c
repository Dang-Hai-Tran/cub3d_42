/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:30:39 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ignore_space_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	ft_ignore_space_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '\n')
		i--;
	while (i >= 0 && str[i] == ' ')
		i--;
	return (i);
}

bool	ft_check_position_map(t_data *data)
{
	if (data->m_map.find_map == true
		&& ft_check_find_elements(data) == false)
	{
		data->error = 1;
		printf("Error: [%d] invalid position of Map !\n",
			data->m_map.line_start);
		return (1);
	}
	return (0);
}

bool	ft_check_start_space(t_data *data)
{
	if (data->m_line.line[0] == ' ')
	{
		data->error = 1;
		printf("Error: [%d] line start with space !\n", data->m_line.id_line);
		return (1);
	}
	return (0);
}

bool	ft_check_end_space(t_data *data, char *str)
{
	int	i;
	int	end;

	i = ft_ignore_space_start(str);
	if (!str[i] || str[i] == '\n')
		return (0);
	end = ft_strlen(str) - 1;
	if (str[end] == '\n')
		end--;
	if (str[end] == ' ' || str[end] == '\t')
	{
		data->error = 1;
		printf("Error: [%d] line end with space !\n", data->m_line.id_line);
		return (1);
	}
	return (0);
}
