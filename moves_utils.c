/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:11:15 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/28 12:15:44 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_process(data, NULL);
	if (keycode == 97 || keycode == 65361)
		ft_printf("[left]	Total moves: %d \n", ++data->moves);
	if (keycode == 115  || keycode == 65364)
		ft_printf("[down]	Total moves: %d \n", ++data->moves);
	if (keycode == 100 || keycode == 65363)
	{
		ft_printf("[right]	Total moves: %d \n", ++data->moves);
		mlx_put_image_to_window(data->mlx, data->window, data->img[2], 64, 0);
	}
	if (keycode == 119 || keycode == 65362)
		ft_printf("[up]	Total moves: %d \n", ++data->moves);
	return (0);
}
