/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:34:01 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/22 19:44:46 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	reslen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	else
		reslen = dlen + slen;
	slen = 0;
	while (dst && src && src[slen] != '\0' && dlen < size - 1)
	{
		dst[dlen] = src[slen];
		dlen++;
		slen++;
	}
	dst[dlen] = '\0';
	return (reslen);
}
