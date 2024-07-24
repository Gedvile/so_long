/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:36:15 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/07 11:30:16 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		res;
	size_t	i;

	res = 0;
	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1) > *((unsigned char *)s2))
			return (1);
		else if (*((unsigned char *)s1) < *((unsigned char *)s2))
			return (-1);
		s1++;
		s2++;
		i++;
	}
	return (res);
}
