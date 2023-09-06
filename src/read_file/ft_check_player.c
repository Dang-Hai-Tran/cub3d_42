/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:32:03 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_find_player(t_data *data)
{
	if (data->m_player.find_player == false)
	{
		printf("Error: not found Player on map !\n");
		return (1);
	}
	return (0);
}

bool	ft_check_nomber_player(t_data *data, char *str)
{
	static int	nbr_player = 0;
	int			i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == 'N'
			|| str[i] == 'S'
			|| str[i] == 'E'
			|| str[i] == 'W')
		{
			if (data->m_player.find_player == false)
				data->m_player.find_player = true;
			nbr_player++;
		}
		i++;
	}
	if (nbr_player > 1)
	{
		printf("Error: [%d] there are (%d) players on the map !\n",
			data->m_line.id_line, nbr_player);
		return (1);
	}
	return (0);
}
