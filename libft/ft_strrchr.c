/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:31:25 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/17 02:45:41 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*foundc;

	foundc = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			foundc = s;
		s++;
	}
	if (*s == c)
		foundc = s;
	return ((char *)foundc);
}
