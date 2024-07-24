/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:10:18 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/07 11:31:41 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set && set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_reslen(int start, int end)
{
	if (end - start >= 0)
		return (end - start + 2);
	else
		return (1);
}

static char	*put_str(char *res, char const *s1, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

/*
Params:
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
Return:
	The trimmed string.
	NULL if the allocation fails.
Ext func:
	malloc
Descr:
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	start = -1;
	end = -2;
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		if (!is_inset(s1[i], set))
		{
			if (start == -1)
				start = i;
			end = i;
		}
		i++;
	}
	i = get_reslen(start, end);
	res = (char *)malloc(i * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = put_str(res, s1, start, end);
	return (res);
}
