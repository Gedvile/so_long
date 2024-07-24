/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:35:46 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/05 15:22:04 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*res;
	const unsigned char	*copy;
	size_t				i;

	res = (unsigned char *)dest;
	copy = (const unsigned char *)src;
	i = 0;
	if (res < copy)
	{
		while (i < n)
		{
			res[i] = copy[i];
			i++;
		}
	}
	else if (res > copy)
	{
		i = n;
		while (i > 0)
		{
			res[i - 1] = copy[i - 1];
			i--;
		}
	}
	return (res);
}
