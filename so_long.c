/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 15:54:46 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_process(t_data *data, char *err_msg)
{
	int	i;

	i = 0;
	while (data && data->map && data->map[i])
		free(data->map[i++]);
	if (data && data->map)
		free(data->map);
	i = 0;
	while (i < 5)
	{
		if (data && data->img[i])
			mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	if (data && data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data && data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data)
		free(data);
	if (err_msg)
	{
		if (errno != 0)
			perror(err_msg);
		else
		{
			ft_putstr_fd(err_msg, 2);
			ft_putchar_fd('\n', 2);
		}
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

void	setup_textures(t_data *data)
{
	data->img_addr[0] = "./textures/background.xpm";
	data->img[0] = mlx_xpm_file_to_image(data->mlx, data->img_addr[0],
			&data->img_width[0], &data->img_height[0]);
	if (!data->img[0])
		exit_process(data, "Error: mlx_xpm_file_to_image() background fail");
	data->img_addr[1] = "./textures/wall.xpm";
	data->img[1] = mlx_xpm_file_to_image(data->mlx, data->img_addr[1],
			&data->img_width[1], &data->img_height[1]);
	if (!data->img[1])
		exit_process(data, "Error: mlx_xpm_file_to_image() wall fail");
	data->img_addr[2] = "./textures/player.xpm";
	data->img[2] = mlx_xpm_file_to_image(data->mlx, data->img_addr[2],
			&data->img_width[2], &data->img_height[2]);
	if (!data->img[2])
		exit_process(data, "Error: mlx_xpm_file_to_image() player fail");
	data->img_addr[3] = "./textures/collectible.xpm";
	data->img[3] = mlx_xpm_file_to_image(data->mlx, data->img_addr[3],
			&data->img_width[3], &data->img_height[3]);
	if (!data->img[3])
		exit_process(data, "Error: mlx_xpm_file_to_image() collectible fail");
	data->img_addr[4] = "./textures/exit.xpm";
	data->img[4] = mlx_xpm_file_to_image(data->mlx, data->img_addr[4],
			&data->img_width[4], &data->img_height[4]);
	if (!data->img[4])
		exit_process(data, "Error: mlx_xpm_file_to_image() exit fail");
}

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
				mlx_put_image_to_window(data->mlx, data->window, data->img[0],
					j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->img[1],
					j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->img[2],
					j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->img[3],
					j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->img[4],
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		exit_process(NULL, "Error: invalid number of arguments");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit_process(data, "Error: data malloc() fail");
	ft_memset(data, 0, sizeof(t_data));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		exit_process(data, "Error: invalid map file");
	init_map(argv[1], data);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_process(data, "Error: mlx_init() fail");
	data->window = mlx_new_window(data->mlx,
			data->width, data->height, "so_long");
	if (!data->window)
		exit_process(data, "Error: mlx_new_window() fail");
	setup_textures(data);
	add_textures(data);
	mlx_key_hook(data->window, key_hook, data);
	mlx_hook(data->window, 17, 0, mouse_hook, data);
	mlx_loop(data->mlx);
	exit_process(data, NULL);
	return (0);
}
