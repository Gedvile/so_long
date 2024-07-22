/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:25:33 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/17 01:01:12 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Params:
	s: The string to output.
	fd: The file descriptor on which to write.
Return:
	None
Ext func:
	write
Descr:
	Outputs the string ’s’ to the given file descriptor followed by a newline.
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, &"\n", 1);
}
