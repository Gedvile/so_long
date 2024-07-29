/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:29:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 13:10:13 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* INCLUDES ***************************************************************** */
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

/* DEFINES ****************************************************************** */
# define TILE_SIZE 64

/* STRUCTS ****************************************************************** */
typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	char	**map;
	void	*img[5];
	char	*img_addr[5];
	int		img_width[5];
	int		img_height[5];
	int		player_loc[2]; // [0] - height, [1] - width
	int		collectibles;
	int		moves;
}	t_data;

/* so_long.c **************************************************************** */
void	exit_process(t_data *data, char *err_msg);

/* maps_utils.c ************************************************************* */
void	init_map(char *map_address, t_data *data);

/* moves_utils.c ************************************************************ */
int		key_hook(int keycode, t_data *data);

#endif
