/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/27 19:10:12 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Arguments:
	*.ber (map)
Ext funcs:
	- open, close, read, write, malloc, free, perror, strerror, exit
	- minilibx library
	- math library
	- libft library
*/

#include "so_long.h"

void	exit_process(t_data *data, char *err_msg)
{
	if (data->hero)
		mlx_destroy_image(data->mlx, data->hero);
	if (data->background)
		mlx_destroy_image(data->mlx, data->background);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data)
		free(data);
	if (err_msg)
	{
		perror(err_msg);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

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
		mlx_put_image_to_window(data->mlx, data->window, data->hero, 64, 0);
	}
	if (keycode == 119 || keycode == 65362)
		ft_printf("[up]	Total moves: %d \n", ++data->moves);
	return (0);
}

int	mouse_exit(t_data *data)
{
	exit_process(data, NULL);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data)); // data init
	if (!data)
		exit_process(data, "Error: data malloc() fail\n");
	data->width = 600;
	data->height = 300;
	data->moves = 0;
	data->mlx = mlx_init(); // connection init
	if (!(data->mlx))
		exit_process(data, "Error: mlx_init() fail\n");
	data->window = mlx_new_window(data->mlx, // window init
			data->width, data->height, "so_long");
	if (!(data->window))
		exit_process(data, "Error: mlx_new_window() fail\n");
	data->background_addr = "./textures/green.xpm"; // image init
	data->background = mlx_xpm_file_to_image(data->mlx, data->background_addr,
			&data->background_width, &data->background_height);
	if (!(data->background))
		exit_process(data, "Error: mlx_xpm_file_to_image() fail\n");

	data->hero_addr = "./textures/bee.xpm"; // image init
	data->hero = mlx_xpm_file_to_image(data->mlx, data->hero_addr,
			&data->hero_width, &data->hero_height);
	if (!(data->hero))
		exit_process(data, "Error: mlx_xpm_file_to_image() fail\n");

	mlx_put_image_to_window(data->mlx, data->window, data->background, 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->background, 200, 100);
	mlx_put_image_to_window(data->mlx, data->window, data->background, 400, 200);
	mlx_put_image_to_window(data->mlx, data->window, data->hero, 0, 0);

	mlx_key_hook(data->window, key_hook, data);
	mlx_hook(data->window, 17, 0, mouse_exit, data);
	mlx_loop(data->mlx);

	exit_process(data, NULL);
	return (0);
}
