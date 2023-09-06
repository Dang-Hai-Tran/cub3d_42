/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:15:22 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initialisation_texture(t_texture *texture)
{
	texture->find_no = false;
	texture->find_so = false;
	texture->find_we = false;
	texture->find_ea = false;
	texture->line_no = 0;
	texture->line_so = 0;
	texture->line_we = 0;
	texture->line_ea = 0;
}

void	ft_initialisation_color(t_color *color)
{
	color->find_f = false;
	color->find_c = false;
	color->line_f = 0;
	color->line_c = 0;
	color->nb_number = 0;
}

void	ft_initialisation_map(t_map *map)
{
	map->find_map = false;
	map->width = 0;
	map->height = 0;
	map->line_start = 0;
	map->line_end = 0;
}

void	ft_initialisation_player(t_pplayer *player)
{
	player->find_player = false;
	player->p_col = 0;
	player->p_row = 0;
}

void	ft_initialisation_data(t_data *data)
{
	ft_initialisation_texture(&(data->m_texture));
	ft_initialisation_color(&(data->m_color));
	ft_initialisation_map(&(data->m_map));
	ft_initialisation_player(&(data->m_player));
}
