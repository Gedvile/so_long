/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:36:27 by gklimasa          #+#    #+#             */
/*   Updated: 2024/07/13 18:34:35 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	char	*byte_fill;
	size_t	i;
	size_t	max;

	max = __SIZE_MAX__;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (max / size < nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	byte_fill = (char *)res;
	i = 0;
	while (i < nmemb * size)
	{
		byte_fill[i] = 0;
		i++;
	}
	return (res);
}
