/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:02:03 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_comma(char *str)
{
	int	i;
	int	nb_comma;

	nb_comma = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 || str[i + 1] == 0)
		{
			if (str[i] == ',')
				return (1);
		}
		if (str[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
		return (1);
	return (0);
}

char	*ft_get_str_number_color(char *str)
{
	int		i;
	int		m;
	char	*str_number;

	str_number = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!str_number)
		return (0);
	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	m = 0;
	while (str[i] && str[i] != '\n')
	{
		str_number[m] = str[i];
		m++;
		i++;
	}
	str_number[m] = 0;
	return (str_number);
}

bool	ft_check_number_color(char *str)
{
	char	*str_number;

	str_number = ft_get_str_number_color(str);
	if (!str_number)
		return (1);
	if (ft_check_comma(str_number) == 0)
	{
		if (ft_read_str_number(str_number) == 0)
		{
			free(str_number);
			return (0);
		}
	}
	free(str_number);
	return (1);
}
