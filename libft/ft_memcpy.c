/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:35:24 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/07 11:30:24 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*res;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	res = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		res[i] = *((unsigned char *)src + i);
		i++;
	}
	return (res);
}
