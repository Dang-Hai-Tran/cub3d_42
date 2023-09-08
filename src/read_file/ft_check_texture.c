/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:47:55 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_error_texture(t_texture *texture)
{
	if (texture->id_texture == 1)
		return ("NO");
	if (texture->id_texture == 2)
		return ("SO");
	if (texture->id_texture == 3)
		return ("WE");
	if (texture->id_texture == 4)
		return ("EA");
	return (0);
}

bool	ft_check_identifiant_texture(t_data *data, char *str)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
	{
		data->m_texture.id_texture = 1;
		return (0);
	}
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
	{
		data->m_texture.id_texture = 2;
		return (0);
	}
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
	{
		data->m_texture.id_texture = 3;
		return (0);
	}
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
	{
		data->m_texture.id_texture = 4;
		return (0);
	}
	return (1);
}

bool	ft_check_double_texture(t_texture *texture, int id_line)
{
	if (texture->id_texture == 1 && texture->find_no == false)
	{
		texture->line_no = id_line;
		texture->find_no = true;
	}
	else if (texture->id_texture == 2 && texture->find_so == false)
	{
		texture->line_so = id_line;
		texture->find_so = true;
	}
	else if (texture->id_texture == 3 && texture->find_we == false)
	{
		texture->line_we = id_line;
		texture->find_we = true;
	}
	else if (texture->id_texture == 4 && texture->find_ea == false)
	{
		texture->line_ea = id_line;
		texture->find_ea = true;
	}
	else
		return (1);
	return (0);
}

bool	ft_check_texture(t_data *data, char *str)
{
	if (ft_check_identifiant_texture(data, str) == 1)
		return (1);
	if (ft_check_position_map(data) == 1)
		return (1);
	if (ft_check_double_texture(&(data->m_texture), data->m_line.id_line) == 1)
	{
		printf("Error: [%d] double texture (%s) !\n",
			data->m_line.id_line, ft_error_texture(&(data->m_texture)));
		data->error = 1;
		return (1);
	}
	if (ft_check_path(data, &str[2]) == 1)
		return (1);
	return (0);
}
