/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:18:50 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_find_texture_in_file(t_texture *texture)
{
	if (texture->find_no == 0)
		printf("Error: not found NO !\n");
	else if (texture->find_so == 0)
		printf("Error: not found SO !\n");
	else if (texture->find_we == 0)
		printf("Error: not found WE !\n");
	else if (texture->find_ea == 0)
		printf("Error: not found EA !\n");
	else
		return (0);
	return (1);
}

bool	ft_check_find_color_in_file(t_color *color)
{
	if (color->find_f == 0)
		printf("Error: not found F !\n");
	else if (color->find_c == 0)
		printf("Error: not found C !\n");
	else
		return (0);
	return (1);
}

bool	ft_check_find_map_in_file(t_map *map)
{
	if (map->find_map == 0)
		printf("Error: not found Map !\n");
	else
		return (0);
	return (1);
}

bool	ft_check_file_status(t_data *data, char *file)
{
	if (data->m_line.id_line == 0)
	{
		printf("Error: file vide !\n");
		return (1);
	}
	if (ft_check_find_texture_in_file(&(data->m_texture)) == 1)
		return (1);
	if (ft_check_find_color_in_file(&(data->m_color)) == 1)
		return (1);
	if (ft_check_find_map_in_file(&(data->m_map)) == 1)
		return (1);
	if (ft_check_map_open(data, file) == 1)
		return (1);
	return (0);
}
