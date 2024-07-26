/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/26 13:03:15 by gklimasa         ###   ########.fr       */
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
		ft_printf("a (left) key pressed\n");
	if (keycode == 115  || keycode == 65364)
		ft_printf("s (down) key pressed\n");
	if (keycode == 100 || keycode == 65363)
		ft_printf("d (right) key pressed\n");
	if (keycode == 119 || keycode == 65362)
		ft_printf("w (up) key pressed\n");
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit_process(data, "Error: data malloc() fail\n");
	data->height = 300;
	data->width = 600;
	data->mlx = mlx_init();
	if (!(data->mlx))
		exit_process(data, "Error: mlx_init() fail\n");
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"so_long");
	if (!(data->window))
		exit_process(data, "Error: mlx_new_window() fail\n");

	mlx_key_hook(data->window, key_hook, data);
	mlx_loop(data->mlx);

	exit_process(data, NULL);
	return (0);
}


/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	ft_printf("LETS DO THIS!!!\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 300, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 10;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		i += 10;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
} */
