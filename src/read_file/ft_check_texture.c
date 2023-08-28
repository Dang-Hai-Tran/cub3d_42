/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:10:13 by xuluu             #+#    #+#             */
/*   Updated: 2023/08/28 16:31:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_character_texture(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| str[i] == '.'
			|| str[i] == '/'
			|| str[i] == '_'
			|| str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

bool	ft_check_identifiant_texture(t_texture *texture, char *str)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
	{
		texture->id_texture = 1;
		return (0);
	}
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
	{
		texture->id_texture = 2;
		return (0);
	}
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
	{
		texture->id_texture = 3;
		return (0);
	}
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
	{
		texture->id_texture = 4;
		return (0);
	}
	return (1);
}

bool	ft_check_space_inside_texture(char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

bool	ft_check_path_to_texture(char *str)
{
	int		i;
	int		m;
	char	*path;

	path = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!path)
		return (1);
	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	m = 0;
	while (str[i] && str[i] != '\n')
	{
		path[m] = str[i];
		m++;
		i++;
	}
	path[m] = 0;
	if (ft_check_file(path, ".xpm") == 1)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
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
