/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:56:12 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_identifiant_color(t_data *data, char *str)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		data->m_color.id_color = 1;
		return (0);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		data->m_color.id_color = 2;
		return (0);
	}
	return (1);
}

bool	ft_check_comma(t_data *data, char *str)
{
	int	i;
	int	nb_comma;

	nb_comma = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			nb_comma++;
			if (nb_comma > 2
				|| i == 0
				|| str[i + 1] == 0
				|| str[i - 1] == ',')
			{
				data->error = 1;
				printf("Error: [%d] invalid comma position in Color (%s) !\n",
					data->m_line.id_line, ft_error_color(&(data->m_color)));
				free(str);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

bool	ft_check_character(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ',')
		{
			data->error = 1;
			printf("Error: [%d] invalid character (%c) in color (%s) !\n",
				data->m_line.id_line, str[i], ft_error_color(&(data->m_color)));
			free(str);
			return (1);
		}
		i++;
	}
	return (0);
}

bool	ft_check_str_color(t_data *data, char *str)
{
	int		start;
	int		end;
	char	*str_color;

	start = ft_ignore_space_start(str);
	end = ft_ignore_space_end(str);
	str_color = ft_copy_str(str, start, end);
	if (ft_check_character(data, str_color) == 1)
		return (1);
	if (ft_check_comma(data, str_color) == 1)
		return (1);
	if (ft_check_number_color(data, str_color) == 1)
		return (1);
	free(str_color);
	return (0);
}

bool	ft_check_color(t_data *data, char *str)
{
	if (ft_check_identifiant_color(data, str) == 1)
		return (1);
	if (ft_check_start_space(data) == 1)
		return (1);
	if (ft_check_position_map(data) == 1)
		return (1);
	if (ft_check_double_color(&(data->m_color), data->m_line.id_line) == 1)
	{
		data->error = 1;
		printf("Error: [%d] double color (%s) !\n",
			data->m_line.id_line, ft_error_color(&(data->m_color)));
		return (1);
	}
	if (ft_check_str_color(data, &str[1]) == 1)
		return (1);
	if (ft_check_end_space(data, str) == 1)
		return (1);
	return (0);
}
