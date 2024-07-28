/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:11:15 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/28 16:57:22 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0 - background, 1 - wall, 2 - player, 3 - collectible, 4 - exit
int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_process(data, NULL);
	if (keycode == 97 || keycode == 65361)
	{
		if (data->map[data->player_loc[0]][data->player_loc[1] - 1] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			data->player_loc[1]--;
			mlx_put_image_to_window(data->mlx, data->window, data->img[2],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			ft_printf("[left]	Total moves: %d \n", ++data->moves);
		}
		else
			ft_printf("[left]	Move out of bounds\n");
	}
	if (keycode == 100 || keycode == 65363)
	{
		if (data->map[data->player_loc[0]][data->player_loc[1] + 1] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			data->player_loc[1]++;
			mlx_put_image_to_window(data->mlx, data->window, data->img[2],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			ft_printf("[right]	Total moves: %d \n", ++data->moves);
		}
		else
			ft_printf("[right]	Move out of bounds\n");
		//mlx_put_image_to_window(data->mlx, data->window, data->img[2], 64, 0);
	}
	if (keycode == 119 || keycode == 65362)
	{
		if (data->map[data->player_loc[0] - 1][data->player_loc[1]] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			data->player_loc[0]--;
			mlx_put_image_to_window(data->mlx, data->window, data->img[2],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			ft_printf("[up]	Total moves: %d \n", ++data->moves);
		}
		else
			ft_printf("[up]	Move out of bounds\n");
	}
	if (keycode == 115  || keycode == 65364)
	{
		if (data->map[data->player_loc[0] + 1][data->player_loc[1]] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			data->player_loc[0]++;
			mlx_put_image_to_window(data->mlx, data->window, data->img[2],
				data->player_loc[1] * TILE_SIZE, data->player_loc[0] * TILE_SIZE);
			ft_printf("[down]	Total moves: %d \n", ++data->moves);
		}
		else
			ft_printf("[down]	Move out of bounds\n");
	}
	return (0);
}
