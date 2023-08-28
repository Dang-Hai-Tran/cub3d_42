/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:57:56 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_character_color(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| str[i] == ','
			|| str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

bool	ft_check_identifiant_color(t_color *color, char *str)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		color->id_color = 1;
		return (0);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		color->id_color = 2;
		return (0);
	}
	return (1);
}

bool	ft_check_space_inside_color(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
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
