/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:48:01 by datran            #+#    #+#             */
/*   Updated: 2023/08/13 16:52:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

typedef struct s_display t_display;

int		err_msg(char *str, int code);
void	free_exit(t_display *display, int exit_code);


#endif
