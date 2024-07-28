/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/28 16:44:56 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	check_path(t_data *data, int width, int height)
{


} */

void	validate_map(t_data *data, int width, int height)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!(data->map[i][j] == '0' || data->map[i][j] == '1'
				|| data->map[i][j] == 'P' || data->map[i][j] == 'C'
				|| data->map[i][j] == 'E'))
				exit_process(data, "Error: unrecognized value in map\n");
			if ( i == 0 || j == 0 || i == height - 1 || j == width - 1)
				if (data->map[i][j] != '1')
					exit_process(data, "Error: bad walls\n");
			if (data->map[i][j] == 'P')
			{
				data->player_loc[0] = i;
				data->player_loc[1] = j;
				player++;
			}
			if (data->map[i][j] == 'E')
				exit++;
			if (data->map[i][j] == 'C')
				data->collectibles++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || data->collectibles < 1)
		exit_process(data, "Error: wrong amount of sprites\n");
	//check_path(data, width, height);
}


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
