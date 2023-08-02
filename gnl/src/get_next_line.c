/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:26:37 by copeugne          #+#    #+#             */
/*   Updated: 2022/08/03 09:01:36 by copeugne         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_mallocker(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(size + 1));
	if (!str)
		ft_error_fd_gnl("Error on mallocker\n", 1);
	while (i < size)
		str[i++] = 0;
	str[i] = '\0';
	return (str);
}

int	ft_is_eof(char **line, int fd, int ret, char **str)
{
	if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
	{
		*line = malloc(1);
		if (!line)
			ft_error_fd_gnl("Error on ft is eof\n", 1);
		**line = '\0';
	}
	return (0);
}

int	ft_newline(char **str, char **line, int fd, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_reset(&str[fd]);
		return (0);
	}
	else if (str[fd][i] && str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_reset(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*str[255];
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_mallocker(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (ft_is_eof(line, fd, ret, str));
	return (ft_newline(str, line, fd, ret));
}
