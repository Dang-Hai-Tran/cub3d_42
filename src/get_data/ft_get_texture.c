/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:29 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_texture2(t_data *data, char *str, int id_line)
{
	if (id_line == data->m_texture.line_no)
		data->no_path = str;
	else if (id_line == data->m_texture.line_so)
		data->so_path = str;
	else if (id_line == data->m_texture.line_we)
		data->we_path = str;
	else if (id_line == data->m_texture.line_ea)
		data->ea_path = str;
}

void	ft_get_texture(t_data *data, char *str, int id_line)
{
	int		i;
	char	*str_texture;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	str_texture = ft_get_str(&str[i]);
	ft_get_texture2(data, str_texture, id_line);
}
