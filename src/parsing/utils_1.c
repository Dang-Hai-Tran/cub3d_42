/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:15:47 by datran            #+#    #+#             */
/*   Updated: 2023/08/22 14:44:00 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	if (s1[0] == '\0' && s2[0] == '\0')
		return ((char *)s1);
	while (i >= 0)
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i--;
	}
	return (NULL);
}

char	*remove_white_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (ft_strdup(str + i));
}

bool	check_rgb_value(int *rgb_arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb_arr[i] < 0 || rgb_arr[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

unsigned long rgb_to_hex(int *rgb_arr)
{
	unsigned long	ret;
	int				r;
	int				g;
	int				b;

	r = rgb_arr[0];
	g = rgb_arr[1];
	b = rgb_arr[2];
	ret = ((r && 0xff) << 16) + ((g && 0xff) << 8) + (b && 0xff);
	return (ret);
}
