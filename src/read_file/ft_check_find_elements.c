/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_find_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuluu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:34:24 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 16:35:11 by xuluu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_file_texture(t_texture *texture)
{
	if (texture->find_no == true && texture->find_so == true
		&& texture->find_we == true && texture->find_ea == true)
		return (1);
	return (0);
}

bool	ft_check_find_color(t_color *color)
{
	if (color->find_f == true && color->find_c == true)
		return (1);
	return (0);
}

bool	ft_check_find_elements(t_data *data)
{
	if (ft_check_file_texture(&(data->m_texture)) == true
		&& ft_check_find_color(&(data->m_color)) == true)
		return (1);
	return (0);
}
