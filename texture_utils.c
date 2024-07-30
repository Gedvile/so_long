/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:56:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/30 15:00:09 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// mlx_put_image_to_window() wrapper
void	put_image_to_window(t_data *data, int i, int j, int nr)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img[nr],
		j * TILE_SIZE, i * TILE_SIZE);
}

// add textures to the window for rendering
void	add_textures_to_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				put_image_to_window(data, i, j, BGR_IMG);
			else if (data->map[i][j] == '1')
				put_image_to_window(data, i, j, WALL_IMG);
			else if (data->map[i][j] == 'C')
				put_image_to_window(data, i, j, C_IMG);
			else if (data->map[i][j] == 'E')
				put_image_to_window(data, i, j, E_IMG);
			else if (data->map[i][j] == 'P')
				put_image_to_window(data, i, j, P_IMG);
			j++;
		}
		i++;
	}
}

// add all the needed textures to the game:
// background, wall, player, collectible and exit pictures
void	setup_textures(t_data *data)
{
	data->img_addr[0] = BGR_FILE;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, data->img_addr[BGR_IMG],
			&data->img_width[BGR_IMG], &data->img_height[BGR_IMG]);
	data->img_addr[1] = WALL_FILE;
	data->img[1] = mlx_xpm_file_to_image(data->mlx, data->img_addr[WALL_IMG],
			&data->img_width[WALL_IMG], &data->img_height[WALL_IMG]);
	data->img_addr[2] = C_FILE;
	data->img[2] = mlx_xpm_file_to_image(data->mlx, data->img_addr[C_IMG],
			&data->img_width[C_IMG], &data->img_height[C_IMG]);
	data->img_addr[3] = E_FILE;
	data->img[3] = mlx_xpm_file_to_image(data->mlx, data->img_addr[E_IMG],
			&data->img_width[E_IMG], &data->img_height[E_IMG]);
	data->img_addr[4] = P_FILE;
	data->img[4] = mlx_xpm_file_to_image(data->mlx, data->img_addr[P_IMG],
			&data->img_width[P_IMG], &data->img_height[P_IMG]);
	if (!(data->img[BGR_IMG] && data->img[WALL_IMG] && data->img[C_IMG]
			&& data->img[E_IMG] && data->img[P_IMG]))
		exit_process(data, "Error\nFunction mlx_xpm_file_to_image() fail");
	add_textures_to_window(data);
}
