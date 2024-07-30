/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:11:15 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/30 14:31:34 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// mouse hook on window exit button
int	mouse_hook(t_data *data)
{
	exit_process(data, NULL);
	return (0);
}

// adjust player location variable
void	change_player_loc(t_data *data, char direction)
{
	if (direction == 'w')
		data->player_loc[Y]--;
	else if (direction == 'a')
		data->player_loc[X]--;
	else if (direction == 's')
		data->player_loc[Y]++;
	else if (direction == 'd')
		data->player_loc[X]++;
}

// put background (or exit picture) where the player was,
// put player in the new position on the map and count player moves
void	move_player(t_data *data, char direction)
{
	if (data->map[data->player_loc[Y]][data->player_loc[X]] != 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->img[BGR_IMG],
			data->player_loc[X] * TILE_SIZE, data->player_loc[Y] * TILE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->img[E_IMG],
			data->player_loc[X] * TILE_SIZE, data->player_loc[Y] * TILE_SIZE);
	change_player_loc(data, direction);
	if (data->map[data->player_loc[Y]][data->player_loc[X]] == 'C')
	{
		data->map[data->player_loc[Y]][data->player_loc[X]] = '0';
		data->collectibles--;
	}
	if (data->map[data->player_loc[Y]][data->player_loc[X]] == 'E'
		&& data->collectibles == 0)
	{
		ft_printf("GAME WON!\n");
		exit_process(data, NULL);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img[P_IMG],
		data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
	ft_printf("Moves: %d\n", ++data->moves);
}

// key hooks: exit on ESC, move player on wasd or arrow keys
int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_process(data, NULL);
	if ((keycode == XK_w || keycode == XK_Up)
		&& data->map[data->player_loc[Y] - 1][data->player_loc[X]] != '1')
		move_player(data, 'w');
	if ((keycode == XK_a || keycode == XK_Left)
		&& data->map[data->player_loc[Y]][data->player_loc[X] - 1] != '1')
		move_player(data, 'a');
	if ((keycode == XK_s || keycode == XK_Down)
		&& data->map[data->player_loc[Y] + 1][data->player_loc[X]] != '1')
		move_player(data, 's');
	if ((keycode == XK_d || keycode == XK_Right)
		&& data->map[data->player_loc[Y]][data->player_loc[X] + 1] != '1')
		move_player(data, 'd');
	return (0);
}
