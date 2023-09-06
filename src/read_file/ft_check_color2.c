/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:32:05 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_error_color(t_color *color)
{
	if (color->id_color == 1)
		return ("F");
	if (color->id_color == 2)
		return ("C");
	return (0);
}

bool	ft_check_double_color(t_color *color, int id_line)
{
	if (color->id_color == 1 && color->find_f == false)
	{
		color->line_f = id_line;
		color->find_f = true;
	}
	else if (color->id_color == 2 && color->find_c == false)
	{
		color->line_c = id_line;
		color->find_c = true;
	}
	else
		return (1);
	return (0);
}

char	*ft_get_str_number(char *str)
{
	int		i;
	char	*nbr;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	nbr = (char *)malloc((i + 1) * sizeof(char));
	if (!nbr)
		return (0);
	i = 0;
	while (str[i] && str[i] != ',')
	{
		nbr[i] = str[i];
		i++;
	}
	nbr[i] = 0;
	return (nbr);
}

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

bool	ft_check_number_color(t_data *data, char *str)
{
	int		i;
	char	*nbr;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',')
		{
			nbr = ft_get_str_number(&str[i]);
			if (ft_check_number_color2(data, nbr) == 1)
				return (1);
			i += ft_strlen(nbr);
			free(nbr);
		}
		else
			i++;
	}
	return (0);
}
