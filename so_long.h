/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:29:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/29 19:35:22 by gklimasa         ###   ########.fr       */
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
	char	**map;
	void	*window;
	int		width;
	int		height;
	void	*img[5];
	char	*img_addr[5];
	int		img_width[5];
	int		img_height[5];
	int		player_loc[2];	// [0] - height, [1] - width
	int		collectibles;
	int		moves;
}	t_data;

/* so_long.c **************************************************************** */
void	exit_process(t_data *data, char *err_msg);

/* read_map_utils.c ********************************************************* */
void	init_map(char *map_address, t_data *data);

/* validate_map_utils.c ***************************************************** */
void	validate_map(t_data *data, int width, int height);

/* texture_utils.c ********************************************************** */
void	setup_textures(t_data *data);
void	add_textures(t_data *data);

/* hook_utils.c ************************************************************* */
int		key_hook(int keycode, t_data *data);
int		mouse_hook(t_data *data);

#endif
