/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:32:05 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_number_color2(t_data *data, char *str)
{
	int	nbr;

	if (ft_strlen(str) > 1 && str[0] == '0')
	{
		data->error = 1;
		printf("Error: [%d] invalid number (%s) of (%s) !\n",
			data->m_line.id_line, str, ft_error_color(&(data->m_color)));
		free(str);
		return (1);
	}
	nbr = ft_atoi(str);
	if (nbr > 255)
	{
		data->error = 1;
		printf("Error: [%d] (%d) > 255 (%s) !\n",
			data->m_line.id_line, nbr, ft_error_color(&(data->m_color)));
		free(str);
		return (1);
	}
	return (0);
}

bool	ft_check_nomber_number(t_data *data, char *str)
{
	if (data->m_color.nb_number != 3)
	{
		data->error = 1;
		printf("Error: [%d] there are not enough numbers (%s) of (%s) !\n",
			data->m_line.id_line, str, ft_error_color(&(data->m_color)));
		return (1);
	}
	return (0);
}

bool	ft_check_number_color(t_data *data, char *str)
{
	int		i;
	char	*nbr;

	data->m_color.nb_number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ',')
		{
			nbr = ft_get_str_number(&str[i]);
			if (ft_check_number_color2(data, nbr) == 1)
				return (1);
			data->m_color.nb_number++;
			i += ft_strlen(nbr);
			free(nbr);
		}
		else
			i++;
	}
	if (ft_check_nomber_number(data, str) == 1)
		return (1);
	return (0);
}
