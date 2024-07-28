/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/28 12:12:25 by gklimasa         ###   ########.fr       */
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
		exit_process(data, "Error: tmp malloc() fail\n");
	ft_memset(tmp, 0, i * j + 1);
	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() fail\n");
	while ((line = get_next_line(fd)))
	{
		if ((int)ft_strlcat(tmp, line, i * j + 1) > i * j)
		{
			free(line);
			free(tmp);
			close(fd);
			exit_process(data, "Error: tmp ft_strlcat() fail\n");
		}
		free(line);
	}
	close(fd);
	data->map = ft_split(tmp, '\n');
	free(tmp);
	if (!(data->map))
		exit_process(data, "Error: ft_split() fail\n");
	data->width = (i - 1) * TILE_SIZE;
	data->height = j * TILE_SIZE;
}

void	validate_map(char *map_address, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(map_address, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() fail\n");
	i = 0;
	j = 0;
	while ((line = get_next_line(fd)))
	{
		if (j++ == 0)
			i = ft_strlen(line);
		else if (i != (int)ft_strlen(line))
		{
			free(line);
			close(fd);
			exit_process(data, "Error: map is not rectangular\n");
		}
		free(line);
	}
	close(fd);
	if (i < 4 || j < 3)
		exit_process(data, "Error: map is too small\n");
	read_map(map_address, data, i, j);
}
