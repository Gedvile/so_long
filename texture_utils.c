/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:56:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 23:57:13 by gklimasa         ###   ########.fr       */
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
void	add_textures(t_data *data)
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
				put_image_to_window(data, i, j, 0);
			else if (data->map[i][j] == '1')
				put_image_to_window(data, i, j, 1);
			else if (data->map[i][j] == 'P')
				put_image_to_window(data, i, j, 2);
			else if (data->map[i][j] == 'C')
				put_image_to_window(data, i, j, 3);
			else if (data->map[i][j] == 'E')
				put_image_to_window(data, i, j, 4);
			j++;
		}
		i++;
	}
}

// add all the needed textures to the game:
// background, wall, player, collectible and exit picture
void	setup_textures(t_data *data)
{
	data->img_addr[0] = "./textures/background.xpm";
	data->img[0] = mlx_xpm_file_to_image(data->mlx, data->img_addr[0],
			&data->img_width[0], &data->img_height[0]);
	data->img_addr[1] = "./textures/wall.xpm";
	data->img[1] = mlx_xpm_file_to_image(data->mlx, data->img_addr[1],
			&data->img_width[1], &data->img_height[1]);
	data->img_addr[2] = "./textures/player.xpm";
	data->img[2] = mlx_xpm_file_to_image(data->mlx, data->img_addr[2],
			&data->img_width[2], &data->img_height[2]);
	data->img_addr[3] = "./textures/collectible.xpm";
	data->img[3] = mlx_xpm_file_to_image(data->mlx, data->img_addr[3],
			&data->img_width[3], &data->img_height[3]);
	data->img_addr[4] = "./textures/exit.xpm";
	data->img[4] = mlx_xpm_file_to_image(data->mlx, data->img_addr[4],
			&data->img_width[4], &data->img_height[4]);
	if (data->img[0] == NULL || data->img[1] == NULL || data->img[2] == NULL
		|| data->img[3] == NULL || data->img[4] == NULL)
		exit_process(data, "Error\nFunction mlx_xpm_file_to_image() fail");
	add_textures(data);
}
