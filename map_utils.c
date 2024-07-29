/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 17:01:19 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_back(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'o')
				data->map[i][j] = '0';
			else if (data->map[i][j] == 'p' || data->map[i][j] == 'c'
				|| data->map[i][j] == 'e')
				data->map[i][j] = ft_toupper(data->map[i][j]);
			j++;
		}
		i++;
	}
}

int	is_winable(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' || data->map[i][j] == 'C'
				|| data->map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_data *data, int i, int j)
{
	if (i < 0 || j < 0 || i >= data->height / TILE_SIZE
		|| j >= data->width / TILE_SIZE)
		return ;
	if ((data->map[i][j] == '1')
			|| (data->map[i][j] >= 'a' && data->map[i][j] <= 'z'))
		return ;
	if (data->map[i][j] >= 'A' && data->map[i][j] <= 'Z')
		data->map[i][j] = ft_tolower(data->map[i][j]);
	else if (data->map[i][j] == '0')
		data->map[i][j] = 'o';
	flood_fill(data, i + 1, j);
	flood_fill(data, i - 1, j);
	flood_fill(data, i, j + 1);
	flood_fill(data, i, j - 1);
}

void	check_path(t_data *data)
{
	flood_fill(data, data->player_loc[0], data->player_loc[1]);
	if (!is_winable(data))
		exit_process(data, "Error: game can not be won");
	change_back(data);
}

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
				exit_process(data, "Error: unrecognized value in map");
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
				if (data->map[i][j] != '1')
					exit_process(data, "Error: bad walls");
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
		exit_process(data, "Error: wrong amount of sprites");
	check_path(data);
}

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
		exit_process(data, "Error: open() fail");
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
		exit_process(data, "Error: open() fail");
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
