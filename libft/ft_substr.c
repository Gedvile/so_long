/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:55:09 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/17 01:03:35 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Params:
	s:		The string from which to create the substring.
	start:	The start index of the substring in the string ’s’.
	len:	The maximum length of the substring.
Return:
	The substring.
	NULL if the allocation fails.
Ext func:
	malloc.
Descr:
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	reslen;
	size_t	i;

	i = 0;
	if (!s || ft_strlen(s) == 0 || len == 0 || start >= ft_strlen(s))
		reslen = 0;
	else if (ft_strlen(s) - start > len)
		reslen = len;
	else
		reslen = ft_strlen(s) - start;
	res = (char *)malloc((reslen + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (s && start < ft_strlen(s))
	{
		while (s[start] != '\0' && i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
	}
	res[i] = '\0';
	return (res);
}
