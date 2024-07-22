/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:16:36 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/17 23:38:39 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Params:
	s: The string on which to iterate.
	f: The function to apply to each character.
Return:
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
Ext func:
	malloc
Descr:
	Applies the function ’f’ to each character of the string ’s’, and
	passing its index as first argument to create a new string
	(with malloc(3)) resulting from successive applications of ’f’.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
