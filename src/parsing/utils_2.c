/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:50:09 by datran            #+#    #+#             */
/*   Updated: 2023/08/23 10:44:47 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	str_contain_only_digits(char *str)
{
	if (!str || !*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	remove_backslash_end(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = 0;
}
