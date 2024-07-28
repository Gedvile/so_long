/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:29:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/28 12:27:42 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* INCLUDES ***************************************************************** */
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
//# include <math.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

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
	int		moves;
}	t_data;

/* SO_LONG ****************************************************************** */
void	exit_process(t_data *data, char *err_msg);

/* MAPS_UTILS *************************************************************** */
void	validate_map(char *map_address, t_data *data);

/* MOVES_UTILS ************************************************************** */
int		key_hook(int keycode, t_data *data);

#endif
