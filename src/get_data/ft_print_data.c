
# include "cub3d.h"

void	ft_print_map(t_map *map, char **tab)
{
	int	m;
	int	n;

	m = 0;
	while (m < map->height)
	{
		n = 0;
		while (n < map->width)
		{
			printf("%c", tab[m][n]);
			n++;
		}
		printf("\n");
		free(tab[m]);
		m++;
	}
	free(tab);
}

void	ft_print_tab_color(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("[%d]", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
}

void	ft_print_information(t_data *data)
{
	printf("Texture :\n");
	printf("%d: NO --> %s\n", data->m_texture.line_no, data->no_path);
	free(data->no_path);
	printf("%d: SO --> %s\n", data->m_texture.line_so, data->so_path);
	free(data->so_path);
	printf("%d: WE --> %s\n", data->m_texture.line_we, data->we_path);
	free(data->we_path);
	printf("%d: EA --> %s\n", data->m_texture.line_ea, data->ea_path);
	free(data->ea_path);

	printf("\nColor :\n");
	printf("%d: F --> ", data->m_color.line_f);
	ft_print_tab_color(data->rgb_floor);
	printf("%d: C --> ", data->m_color.line_c);
	ft_print_tab_color(data->rgb_ceiling);

	printf("\nMap :\n");
	printf("line_start = %d\n", data->m_map.line_start);
	printf("line_end = %d\n", data->m_map.line_end);
	printf("w = %d, h = %d\n\n",
		data->m_map.width, data->m_map.height);
	ft_print_map(&(data->m_map), data->map);

	printf("\nPlayer :\n");
	printf("p_char = %c\n", data->m_player.p_char);
	printf("p_col = %d\n", data->m_player.p_col);
	printf("p_row = %d\n", data->m_player.p_row);
}
