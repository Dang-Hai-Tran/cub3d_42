/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:46:57 by copeugne          #+#    #+#             */
/*   Updated: 2023/08/16 10:59:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		ft_error_fd_gnl("Error on strjoin\n", 1);
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

void	ft_reset(char **str)
{
	free(*str);
	*str = NULL;
	return ;
}

char	*ft_substr(char const *s, int start, size_t len)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = malloc(((len + 1) * sizeof(char)));
	if (!tmp || !s)
		ft_error_fd_gnl("Error on substr\n", 1);
	if (start > ft_strlen(s))
	{
		tmp[0] = '\0';
		return (tmp);
	}
	while (i < len && s[start])
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	while (s1[i])
// 		i++;
// 	tmp = (char *)malloc((i * sizeof(char)) + 1);
// 	if (!tmp)
// 		ft_error_fd_gnl("Error on strjoin\n", 1);
// 	i = -1;
// 	while (s1[++i])
// 		tmp[i] = s1[i];
// 	tmp[i] = '\0';
// 	return (tmp);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	if (c == 0)
// 	{
// 		while (*s)
// 			s++;
// 		return ((char *) s);
// 	}
// 	while (*s)
// 	{
// 		if (*s == (unsigned char)c)
// 			return ((char *) s);
// 		s++;
// 	}
// 	return (0);
// }
