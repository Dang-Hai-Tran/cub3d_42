/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:48:01 by datran            #+#    #+#             */
/*   Updated: 2023/08/28 16:44:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "cub3d.h"

typedef enum e_dir			t_dir;
typedef enum e_code			t_code;
typedef struct s_img		t_img;
typedef struct s_texinfo	t_texinfo;
typedef struct s_mapinfo	t_mapinfo;
typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_display	t_display;

void	free_exit(t_display *display, int exit_code);
int		err_msg(char *str, int code);
int		quit_cub3d(t_display *display);
void	free_arr(void **arr);
void	free_display(t_display *display);

#endif
