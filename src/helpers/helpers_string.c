/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:37:41 by codespace         #+#    #+#             */
/*   Updated: 2023/08/16 18:29:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int			sign;
	long		res;
	const char	*start_digits;

	if (base != 10)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	res = 0;
	start_digits = nptr;
	while (ft_isdigit(*nptr))
	{
		if (res > (LONG_MAX - (*nptr - '0')) / 10)
		{
			if (sign == 1)
				res = LONG_MAX;
			else
				res = LONG_MIN;
			if (endptr)
				*endptr = (char *)nptr;
			return (res);
		}
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (start_digits == nptr)
	{
		if (endptr)
			*endptr = (char *)start_digits;
		return (0);
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (res * sign);
}

char	*skip_whitespace(char *line)
{
	while (*line && ft_isspace((unsigned char)*line))
		line++;
	return (line);
}
