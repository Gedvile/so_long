/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:11:15 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 15:07:23 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, char direction)
{
	if (data->map[data->player_loc[0]][data->player_loc[1]] != 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->img[0],
			data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->img[4],
			data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	if (direction == 'L')
		data->player_loc[1]--;
	else if (direction == 'R')
		data->player_loc[1]++;
	else if (direction == 'U')
		data->player_loc[0]--;
	else if (direction == 'D')
		data->player_loc[0]++;
	if (data->map[data->player_loc[0]][data->player_loc[1]] == 'C')
	{
		data->map[data->player_loc[0]][data->player_loc[1]] = '0';
		data->collectibles--;
	}
	if (data->map[data->player_loc[0]][data->player_loc[1]] == 'E')
	{
		if (data->collectibles == 0)
		{
			ft_printf("Game won!");
			exit_process(data, NULL);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img[2],
		data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	ft_printf("Moves: %d\n", ++data->moves);
}

// 0 - background, 1 - wall, 2 - player, 3 - collectible, 4 - exit
int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_process(data, NULL);
	if (keycode == 97 || keycode == 65361)
	{
		if (data->map[data->player_loc[0]][data->player_loc[1] - 1] != '1')
			move_player(data, 'L');
	}
	if (keycode == 100 || keycode == 65363)
	{
		if (data->map[data->player_loc[0]][data->player_loc[1] + 1] != '1')
			move_player(data, 'R');
	}
	if (keycode == 119 || keycode == 65362)
	{
		if (data->map[data->player_loc[0] - 1][data->player_loc[1]] != '1')
			move_player(data, 'U');
	}
	if (keycode == 115 || keycode == 65364)
	{
		if (data->map[data->player_loc[0] + 1][data->player_loc[1]] != '1')
			move_player(data, 'D');
	}
	return (0);
}
