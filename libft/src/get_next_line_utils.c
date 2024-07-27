/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:14:03 by gklimasa          #+#    #+#             */
/*   Updated: 2024/04/24 12:03:05 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_lnlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (i + 1);
			i++;
		}
	}
	return (i);
}

static int	fill_line(char *dest, int start, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[start++] = src[i++];
		if (src[i - 1] == '\n')
			return (start);
	}
	return (start);
}

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

void	trim_buffer(char *buffer)
{
	int	start;
	int	i;

	start = get_lnlen(buffer);
	if (buffer[start] == '\0')
	{
		buffer[0] = '\0';
		return ;
	}
	i = 0;
	while (buffer[start] != '\0')
		buffer[i++] = buffer[start++];
	buffer[i] = '\0';
}

char	*append_buffer(char *line, char *buffer)
{
	char	*res;
	int		len;
	int		i;

	len = get_lnlen(line) + get_lnlen(buffer);
	if (len <= 0)
		return (NULL);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
	{
		if (line)
			free(line);
		buffer[0] = '\0';
		return (NULL);
	}
	i = 0;
	if (line)
	{
		i = fill_line(res, i, line);
		free(line);
	}
	fill_line(res, i, buffer);
	res[len] = '\0';
	return (res);
}
