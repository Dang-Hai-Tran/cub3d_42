/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_outside_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:26:33 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_line_start_and_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

bool	ft_check_end_line(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == '\n')
		i--;
	while (i > 0 && str[i] == ' ')
		i--;
	if (str[i] != '1')
		return (1);
	return (0);
}

bool	ft_check_start_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (1);
	return (0);
}

bool	ft_check_line_map_open(char *str)
{
	if (ft_check_start_line(str) == 0)
	{
		if (ft_check_end_line(str) == 0)
			return (0);
	}
	return (1);
}
