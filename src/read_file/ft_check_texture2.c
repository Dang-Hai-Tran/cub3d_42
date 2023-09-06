/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:41:51 by xuluu             #+#    #+#             */
/*   Updated: 2023/09/06 15:06:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_copy_str(char *str, int start, int end)
{
	int		i;
	char	*path;

	path = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!path)
		return (0);
	i = 0;
	while (start <= end)
	{
		path[i] = str[start];
		start++;
		i++;
	}
	path[i] = 0;
	return (path);
}

bool	ft_check_path(t_data *data, char *str)
{
	int		start;
	int		end;
	char	*path;
	bool	error;

	start = ft_ignore_space_start(str);
	end = ft_ignore_space_end(str);
	path = ft_copy_str(str, start, end);
	error = false;
	if (ft_check_file(path, ".xpm", data->m_line.id_line,
			ft_error_texture(&(data->m_texture))) == 1)
	{
		data->error = 1;
		error = true;
	}
	free(path);
	return (error);
}
