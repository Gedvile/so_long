/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/23 19:32:14 by gklimasa         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
}
