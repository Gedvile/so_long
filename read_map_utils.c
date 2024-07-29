/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 17:26:08 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map_address, t_data *data, int i, int j)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char *) * (i * j + 1));
	if (!tmp)
		exit_process(data, "Error: tmp malloc() fail");
	ft_memset(tmp, 0, i * j + 1);
	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() map file fail");
	line = get_next_line(fd);
	while (line)
	{
		if ((int)ft_strlcat(tmp, line, i * j + 1) > i * j)
		{
			free(line);
			free(tmp);
			close(fd);
			exit_process(data, "Error: tmp ft_strlcat() fail");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map = ft_split(tmp, '\n');
	free(tmp);
	if (!data->map)
		exit_process(data, "Error: ft_split() fail");
	data->width = (i - 1) * TILE_SIZE;
	data->height = j * TILE_SIZE;
	validate_map(data, i - 1, j);
}

void	init_map(char *map_address, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() map file fail");
	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (j++ == 0)
			i = ft_strlen(line);
		else if (i != (int)ft_strlen(line))
		{
			free(line);
			close(fd);
			exit_process(data, "Error: map is not rectangular");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (i < 4 || j < 3)
		exit_process(data, "Error: map is too small");
	read_map(map_address, data, i, j);
}
