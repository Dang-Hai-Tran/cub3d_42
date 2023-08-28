/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number_color2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:43:02 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_char_number_color(char *str)
{
	int		i;
	char	*nbr;

	nbr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
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

bool	ft_check_str_number(char *str)
{
	if (ft_strlen(str) > 3)
		return (1);
	if (ft_strlen(str) > 1 && str[0] == '0')
		return (1);
	if (ft_strlen(str) == 3 && str[0] > '2')
		return (1);
	if (ft_atoi(str) > 255)
		return (1);
	return (0);
}

bool	ft_read_str_number(char *str)
{
	int		i;
	bool	check;
	char	*nbr;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',')
		{
			nbr = ft_get_char_number_color(&str[i]);
			check = ft_check_str_number(nbr);
			i += ft_strlen(nbr);
			free(nbr);
			if (check == 1)
				return (1);
		}
		else
			i++;
	}
	return (0);
}
