/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:08:58 by copeugne          #+#    #+#             */
/*   Updated: 2023/08/02 12:40:10 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	ft_putstr_fd_gnl(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		ft_putchar_fd_gnl(*s, fd);
		s++;
	}
}

void	ft_putchar_fd_gnl(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_error_fd_gnl(char *str, int fd)
{
	ft_putstr_fd_gnl(str, fd);
	exit(1);
}

char	*ft_strndup(char *s, int n)
{
	char	*dest;
	int		i;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}