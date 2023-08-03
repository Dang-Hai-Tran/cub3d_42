/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:04 by colin             #+#    #+#             */
/*   Updated: 2023/08/03 01:06:30 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3d.h"

// read the .cub file line by line and parse it
int map_reader(char *filename)
{
    int file;
    char *line;
    int i;
    
    i = 0;
    #include <fcntl.h>

    #include <fcntl.h>

    file = open(filename, O_RDONLY);
    if (file == -1)
    {
        perror("Error opening file");
        return (-1);
    }
    while(get_next_line(file, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(file);
    return (0);
}

int map_parser(char *filename)
{
    if (map_reader(filename) == -1)
        return (-1);
    return (0);
}