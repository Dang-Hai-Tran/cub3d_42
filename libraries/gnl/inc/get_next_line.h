/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:32:21 by copeugne          #+#    #+#             */
/*   Updated: 2023/03/21 20:49:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1

void			ft_reset(char **str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, size_t start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char            *ft_strndup(char *s, int n);
int				ft_newline(char **str, char **line, int fd, int ret);
size_t			ft_strlen(const char *s);
int				get_next_line(int fd, char **line);
int				ft_is_eof(char **line, int fd, int ret, char **str);
char			*ft_mallocker(size_t size);
void			ft_putchar_fd_gnl(char c, int fd);
void			ft_putstr_fd_gnl(char *s, int fd);
void			ft_error_fd_gnl(char *str, int fd);

#endif