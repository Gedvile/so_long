/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/30 00:04:27 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// write the error message if it is not NULL and exit the program
void	message_and_exit(char *err_msg)
{
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

// free all the data struct
void	exit_process(t_data *data, char *err_msg)
{
	int	i;

	i = 0;
	while (data && data->map && data->map[i])
		free(data->map[i++]);
	if (data && data->map)
		free(data->map);
	i = 0;
	while (data && i < IMG_COUNT)
	{
		if (data->img[i])
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
	message_and_exit(err_msg);
}

// init data struct, setup map, mlx server, window, textures, hooks, loop
int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		exit_process(NULL, "Error\nInvalid number of arguments");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		exit_process(NULL, "Error\nInvalid map file extension");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit_process(data, "Error\nStruct malloc() fail");
	ft_memset(data, 0, sizeof(t_data));
	init_map(argv[1], data);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_process(data, "Error\nFunction mlx_init() fail");
	data->window = mlx_new_window(data->mlx,
			data->width, data->height, "so_long");
	if (!data->window)
		exit_process(data, "Error\nFunction mlx_new_window() fail");
	setup_textures(data);
	mlx_key_hook(data->window, key_hook, data);
	mlx_hook(data->window, 17, 0, mouse_hook, data);
	mlx_loop(data->mlx);
	exit_process(data, NULL);
	return (0);
}
