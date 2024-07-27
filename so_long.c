/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:29 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/28 01:03:38 by gklimasa         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	if (data->map)
		free(data->map);
	i = 0;
	while (i < 5)
	{
		if (data->img[i])
			mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
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

void	setup_textures(t_data *data)
{
	data->img_addr[0] = "./textures/background.xpm";
	data->img[0] = mlx_xpm_file_to_image(data->mlx, data->img_addr[0],
			&data->img_width[0], &data->img_height[0]);
	if (!(data->img[0]))
		exit_process(data, "Error: mlx_xpm_file_to_image() background fail\n");
	data->img_addr[1] = "./textures/wall.xpm";
	data->img[1] = mlx_xpm_file_to_image(data->mlx, data->img_addr[1],
			&data->img_width[1], &data->img_height[1]);
	if (!(data->img[1]))
		exit_process(data, "Error: mlx_xpm_file_to_image() wall fail\n");
	data->img_addr[2] = "./textures/player.xpm";
	data->img[2] = mlx_xpm_file_to_image(data->mlx, data->img_addr[2],
			&data->img_width[2], &data->img_height[2]);
	if (!(data->img[2]))
		exit_process(data, "Error: mlx_xpm_file_to_image() player fail\n");
	data->img_addr[3] = "./textures/sprite.xpm";
	data->img[3] = mlx_xpm_file_to_image(data->mlx, data->img_addr[3],
			&data->img_width[3], &data->img_height[3]);
	if (!(data->img[3]))
		exit_process(data, "Error: mlx_xpm_file_to_image() sprite fail\n");
	data->img_addr[4] = "./textures/home.xpm";
	data->img[4] = mlx_xpm_file_to_image(data->mlx, data->img_addr[4],
			&data->img_width[4], &data->img_height[4]);
	if (!(data->img[4]))
		exit_process(data, "Error: mlx_xpm_file_to_image() home fail\n");
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
		mlx_put_image_to_window(data->mlx, data->window, data->img[2], 64, 0);
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

void	read_map(char *map, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	*tmp;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() fail\n");
	i = 0;
	j = 0;
	while ((line = get_next_line(fd)))
	{
		if (i == 0)
			j = ft_strlen(line);
		else if (j != (int)ft_strlen(line))
		{
			free(line);
			close(fd);
			exit_process(data, "Error: map is not rectangular\n");
		}
		ft_printf("%s", line);
		ft_printf("- line length %d\n", ft_strlen(line));
		free(line);
		i++;
	}
	close(fd);
	ft_printf("Map size: %d x %d\n", j, i);
	if (i < 3 || j < 3)
		exit_process(data, "Error: map is too small\n");

	tmp = (char *)malloc(sizeof(char *) * (i * j + 1));
	if (!tmp)
		exit_process(data, "Error: tmp malloc() fail\n");
	ft_memset(tmp, 0, i * j + 1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() fail\n");
	while ((line = get_next_line(fd)))
	{
		if ((int)ft_strlcat(tmp, line, i * j + 1) > i * j)
		{
			free(line);
			free(tmp);
			close(fd);
			exit_process(data, "Error: tmp malloc() fail\n");
		}
		free(line);
	}
	data->map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);

	/* data->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->map)
		exit_process(data, "Error: map malloc() fail\n");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_process(data, "Error: open() fail\n");
	i = 0;
	while ((line = get_next_line(fd)))
	{
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			exit_process(data, "Error: map malloc() fail\n");
		free(line);
		i++;
	}
	data->map[i] = NULL;
	close(fd); */
}

int	main(void)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(sizeof(t_data)); // data init
	if (!data)
		exit_process(data, "Error: data malloc() fail\n");
	ft_memset(data, 0, sizeof(t_data));

	read_map("maps/map.ber", data);
	i = 0;
	while (data->map && data->map[i])
		ft_printf("%s\n", data->map[i++]);

	data->width = 600;
	data->height = 300;
	data->mlx = mlx_init(); // connection init
	if (!(data->mlx))
		exit_process(data, "Error: mlx_init() fail\n");
	data->window = mlx_new_window(data->mlx, // window init
			data->width, data->height, "so_long");
	if (!(data->window))
		exit_process(data, "Error: mlx_new_window() fail\n");

	setup_textures(data);

	mlx_put_image_to_window(data->mlx, data->window, data->img[0], 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->img[1], 200, 100);
	mlx_put_image_to_window(data->mlx, data->window, data->img[3], 400, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->img[4], 400, 200);
	mlx_put_image_to_window(data->mlx, data->window, data->img[2], 0, 0);

	mlx_key_hook(data->window, key_hook, data);
	mlx_hook(data->window, 17, 0, mouse_exit, data);
	mlx_loop(data->mlx);

	exit_process(data, NULL);
	return (0);
}
