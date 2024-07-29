/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:11:15 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 16:25:01 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// adjust player location variable
void	change_player_loc(t_data *data, char direction)
{
	if (direction == 'a')
		data->player_loc[1]--;
	else if (direction == 'w')
		data->player_loc[0]--;
	else if (direction == 'd')
		data->player_loc[1]++;
	else if (direction == 's')
		data->player_loc[0]++;
}

// put background (or exit picture) where the player was,
// put player in the new position on the map and count player moves
void	move_player(t_data *data, char direction)
{
	if (data->map[data->player_loc[0]][data->player_loc[1]] != 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->img[0],
			data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->img[4],
			data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	change_player_loc(data, direction);
	if (data->map[data->player_loc[0]][data->player_loc[1]] == 'C')
	{
		data->map[data->player_loc[0]][data->player_loc[1]] = '0';
		data->collectibles--;
	}
	if (data->map[data->player_loc[0]][data->player_loc[1]] == 'E'
		&& data->collectibles == 0)
	{
		ft_printf("Game won!");
		exit_process(data, NULL);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img[2],
		data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	ft_printf("Moves: %d\n", ++data->moves);
}

// key hooks: esc = 65307
// a = 97, left = 65361
// w = 119, up = 65362
// d = 100, right = 65363
// s = 115, down = 65364
int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_process(data, NULL);
	if ((keycode == 97 || keycode == 65361)
		&& data->map[data->player_loc[0]][data->player_loc[1] - 1] != '1')
		move_player(data, 'a');
	if ((keycode == 119 || keycode == 65362)
		&& data->map[data->player_loc[0] - 1][data->player_loc[1]] != '1')
		move_player(data, 'w');
	if ((keycode == 100 || keycode == 65363)
		&& data->map[data->player_loc[0]][data->player_loc[1] + 1] != '1')
		move_player(data, 'd');
	if ((keycode == 115 || keycode == 65364)
		&& data->map[data->player_loc[0] + 1][data->player_loc[1]] != '1')
		move_player(data, 's');
	return (0);
}

// mouse hook on window exit button
int	mouse_hook(t_data *data)
{
	exit_process(data, NULL);
	return (0);
}
