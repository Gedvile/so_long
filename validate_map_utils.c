/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:22:30 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/30 07:27:30 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if after flood_fill() all the sprites are reachable
// and change the flood_fill() modified characters back to original state
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
			if (data->map[i][j] >= 'A' && data->map[i][j] <= 'Z')
				return (0);
			if (data->map[i][j] == 'o')
				data->map[i][j] = '0';
			else if (data->map[i][j] >= 'a' && data->map[i][j] <= 'z')
				data->map[i][j] = ft_toupper(data->map[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}

// fill stored map's accessible path with different characters
void	flood_fill(t_data *data, int i, int j)
{
	if (i < 0 || i >= data->height / TILE_SIZE
		|| j < 0 || j >= data->width / TILE_SIZE)
		return ;
	if (ft_strchr("1ceop", data->map[i][j]) != NULL)
		return ;
	if (data->map[i][j] == '0')
		data->map[i][j] = 'o';
	else if (data->map[i][j] >= 'A' && data->map[i][j] <= 'Z')
		data->map[i][j] = ft_tolower(data->map[i][j]);
	flood_fill(data, i + 1, j);
	flood_fill(data, i - 1, j);
	flood_fill(data, i, j + 1);
	flood_fill(data, i, j - 1);
}

//	check if stored map has 1 player, 1 exit and 1 or more collectibles
void	validate_sprites(t_data *data)
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
			if (data->map[i][j] == 'C')
				data->collectibles++;
			else if (data->map[i][j] == 'E')
				exit++;
			else if (data->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1 && exit != 1 && data->collectibles < 1)
		exit_process(data, "Error\nInvalid amount of sprites in the map");
}

// check if stored map has only valid characters and a valid wall
void	validate_chars_and_wall(t_data *data, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("01CEP", data->map[i][j]) == NULL)
				exit_process(data, "Error\nInvalid character in the map");
			if ((i == 0 || j == 0 || i == height - 1 || j == width - 1)
				&& data->map[i][j] != '1')
				exit_process(data, "Error\nInvalid walls in the map");
			j++;
		}
		i++;
	}
}

// initiate stored map's validation, set player's location
void	validate_map(t_data *data, int width, int height)
{
	int	i;
	int	j;

	validate_chars_and_wall(data, width, height);
	validate_sprites(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != 'P')
			j++;
		if (data->map[i][j] && data->map[i][j] == 'P')
		{
			data->player_loc[Y] = i;
			data->player_loc[X] = j;
			break ;
		}
		i++;
	}
	flood_fill(data, data->player_loc[0], data->player_loc[1]);
	if (!is_winable(data))
		exit_process(data, "Error\nGame can not be won");
}
