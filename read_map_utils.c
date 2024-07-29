/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 21:07:59 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// allocate memory to a string and fill it with 0s
char	*str_malloc_fill(t_data *data, int size)
{
	char	*str;

	str = (char *)malloc(size * sizeof(char));
	if (!str)
		exit_process(data, "Error: str malloc() fail");
	ft_memset(str, 0, size);
	return (str);
}

// read map file to store the map into the game struct
void	store_map(char *map_address, t_data *data, int i, int j)
{
	int		fd;
	char	*line;
	char	*str;

	str = str_malloc_fill(data, i * j + 1);
	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() map file fail");
	line = get_next_line(fd);
	while (line)
	{
		if ((int)ft_strlcat(str, line, i * j + 1) > i * j)
		{
			free(line);
			free(str);
			close(fd);
			exit_process(data, "Error: str ft_strlcat() fail");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map = ft_split(str, '\n');
	free(str);
}

// read map file to get map's dimensions
void	get_map_size(char *map_address, t_data *data, int *i, int *j)
{
	int		fd;
	char	*line;

	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() map file fail");
	line = get_next_line(fd);
	while (line)
	{
		if (*j == 0)
			*i = ft_strlen(line);
		else if (*i != (int)ft_strlen(line))
		{
			free(line);
			close(fd);
			exit_process(data, "Error: map is not rectangular");
		}
		free(line);
		line = get_next_line(fd);
		(*j)++;
	}
	close(fd);
}

// initiate map reading, set window size according to map, send map to validate
void	init_map(char *map_address, t_data *data)
{
	int	i;
	int	j;
	int	*i_ptr;
	int	*j_ptr;

	i = 0;
	j = 0;
	i_ptr = &i;
	j_ptr = &j;
	get_map_size(map_address, data, i_ptr, j_ptr);
	if (i < 4 || j < 3)
		exit_process(data, "Error: map is too small");
	store_map(map_address, data, i, j);
	if (!data->map)
		exit_process(data, "Error: ft_split() fail");
	data->width = (i - 1) * TILE_SIZE;
	data->height = j * TILE_SIZE;
	validate_map(data, i - 1, j);
}
