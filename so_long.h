/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:29:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/30 14:57:19 by gklimasa         ###   ########.fr       */
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
# include <X11/Xlib.h>
# include <X11/keysym.h>

/* DEFINES ****************************************************************** */
# define TILE_SIZE 64
# define IMG_COUNT 5
# define BGR_FILE "./textures/background.xpm"
# define WALL_FILE "./textures/wall.xpm"
# define C_FILE "./textures/collectible.xpm"
# define E_FILE "./textures/exit.xpm"
# define P_FILE "./textures/player.xpm"
# define BGR_IMG 0
# define WALL_IMG 1
# define C_IMG 2
# define E_IMG 3
# define P_IMG 4
# define Y 0
# define X 1

/* STRUCTS ****************************************************************** */
typedef struct s_data
{
	void	*mlx;
	char	**map;
	void	*window;
	int		width;
	int		height;
	void	*img[IMG_COUNT];
	char	*img_addr[IMG_COUNT];
	int		img_width[IMG_COUNT];
	int		img_height[IMG_COUNT];
	int		player_loc[2];
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

/* hook_utils.c ************************************************************* */
int		key_hook(int keycode, t_data *data);
int		mouse_hook(t_data *data);

#endif
