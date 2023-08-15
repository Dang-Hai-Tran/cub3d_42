/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:48:01 by datran            #+#    #+#             */
/*   Updated: 2023/08/15 11:28:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

#include "cub3d.h"

typedef struct s_img t_img;
typedef struct s_text t_text;
typedef struct s_map t_map;
typedef struct s_player t_player;
typedef struct s_ray t_ray;
typedef struct s_display t_display;

void	free_exit(t_display *display, int exit_code);
int		err_msg(char *str, int code);
void	ft_error_fd(char *str, int fd, t_display *display);

#endif
