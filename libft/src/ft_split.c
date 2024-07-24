/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:47:36 by gklimasa          #+#    #+#             */
/*   Updated: 2024/03/20 17:31:25 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s && s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		if (i != 0 && s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	set_malloc(char **res, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	while (s && s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			start = 0;
		if (i != 0 && s[i - 1] == c && s[i] != c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[j] = (char *)malloc((i - start + 2) * sizeof(char));
			if (res[j] == NULL)
				return (0);
			ft_memset(res[j], 0, i - start + 2);
			j++;
		}
		i++;
	}
	return (1);
}

static void	put_strings(char **res, char const *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (s && s[i] != '\0' && res[n] != NULL)
	{
		if (s[i] != c)
		{
			res[n][j] = s[i];
			j++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\n'))
		{
			res[n][j] = '\0';
			j = 0;
			n++;
		}
		i++;
	}
}

/*
Params:
	s: The string to be split.
	c: The delimiter character.
Return:
	The array of new strings resulting from the split.
	NULL if the allocation fails.
Ext funcs:
	malloc, free
Descr:
	Allocates (with malloc(3)) and returns an array of strings obtained by
	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.
 */
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		string_count;
	int		is_malloc;

	string_count = count_strings(s, c);
	res = malloc((string_count + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[string_count] = NULL;
	if (string_count <= 0)
		return (res);
	is_malloc = set_malloc(res, s, c);
	if (!is_malloc)
	{
		free_all(res);
		return (NULL);
	}
	put_strings(res, s, c);
	return (res);
}
