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
