/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:40:20 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:47:36 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_nombre_player(t_pplayer *player, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == 'N'
			|| str[i] == 'S'
			|| str[i] == 'W'
			|| str[i] == 'E')
		{
			if (player->find_player == false)
				player->find_player = true;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
