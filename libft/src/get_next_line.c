/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gklimasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:50:20 by gklimasa          #+#    #+#             */
/*   Updated: 2024/04/24 13:06:38 by gklimasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Params:
	fd: The file descriptor to read from
Return:
	Read line: correct behavior
	NULL: there is nothing else to read, or an error occurred
Ext functs:
	read, malloc, free
Descr:
	Write a function that returns a line read from a file descriptor
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!is_newline(line))
	{
		if (!buffer[0])
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0 && !line)
				return (NULL);
			if (bytes_read <= 0 && line)
				return (line);
			buffer[bytes_read] = '\0';
		}
		line = append_buffer(line, buffer);
		if (!line)
			return (NULL);
		trim_buffer(buffer);
	}
	return (line);
}

/* int	main(void)
{
	char	*res;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while ((res = get_next_line(fd)))
	{
		printf("\n-------------res-------------\n%s-\n\n", res);
		free(res);
	}
	close(fd);
	return (0);
} */
