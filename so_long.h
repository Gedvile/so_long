/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:29:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/26 16:34:15 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	void	*img;
	char	*img_addr;
	int		img_width;
	int		img_height;
	int		moves;
}	t_data;

#endif
