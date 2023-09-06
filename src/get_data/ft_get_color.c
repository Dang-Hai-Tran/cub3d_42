/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:18 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:05:34 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_get_color2(char *str)
{
	int		i;
	int		m;
	int		*tab_color;
	char	*nbr;

	tab_color = (int *)malloc(3 * sizeof(int));
	if (!tab_color)
		return (0);
	m = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ',')
		{
			nbr = ft_get_str_number(&str[i]);
			tab_color[m] = ft_atoi(nbr);
			m++;
			i += ft_strlen(nbr);
			free(nbr);
		}
		else
			i++;
	}
	return (tab_color);
}

void	ft_get_color(t_data *data, char *str, int id_line)
{
	int		i;
	char	*str_color;

	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	str_color = ft_get_str(&str[i]);
	if (id_line == data->m_color.line_f)
		data->rgb_floor = ft_get_color2(str_color);
	else if (id_line == data->m_color.line_c)
		data->rgb_ceiling = ft_get_color2(str_color);
	free(str_color);
}
