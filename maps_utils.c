/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 00:11:21 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	// current coordinates out of bounds
	if (i < 0 || j < 0 || i >= data->height / TILE_SIZE
						|| j >= data->width / TILE_SIZE) // check if max is ok
		return ;

	// current coordinates are a wall or already filled
	if ((data->map[i][j] == '1')
			|| (data->map[i][j] >= 'a' && data->map[i][j] <= 'z'))
		return ;

	// current coordinates are background, player, collectible or exit
	//data->map[i][j] = 'F';
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
	int	i;

	flood_fill(data, data->player_loc[0], data->player_loc[1]);

	ft_printf("\nFilled map:\n");
	i = 0;
	while (data->map && data->map[i])
		ft_printf("%s\n", data->map[i++]);
	ft_printf("\n");

	if (!is_winable(data))
		exit_process(data, "Error: game is not winable\n");

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
	check_path(data);
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
