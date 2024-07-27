/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:29:26 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/26 17:29:35 by gklimasa         ###   ########.fr       */
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
	void	*background;
	char	*background_addr;
	int		background_width;
	int		background_height;
	void	*hero;
	char	*hero_addr;
	int		hero_width;
	int		hero_height;
	int		moves;
}	t_data;

#endif
