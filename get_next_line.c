/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:54:21 by igama             #+#    #+#             */
/*   Updated: 2023/12/16 17:45:56 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_line(char	*bytes_read)
{
	size_t	i;
	char	*new_line;

	i = 0;
	if (!*bytes_read)
		return (NULL);
	while (bytes_read[i] && bytes_read[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (bytes_read[i] != '\n' && bytes_read[i])
	{
		new_line[i] = bytes_read[i];
		i++;
	}
	if (bytes_read[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

static char	*line_left(char *bytes_read)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (bytes_read[i] && bytes_read[i] != '\n')
		i++;
	if (!(bytes_read[i]))
	{
		free(bytes_read);
		return (NULL);
	}
	if (bytes_read[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(bytes_read) + 1 - i));
	if (!rest)
		return (NULL);
	j = 0;
	while (bytes_read[i])
		rest[j++] = bytes_read[i++];
	rest[j] = '\0';
	free(bytes_read);
	return (rest);
}

static char	*read_file(int fd, char *bytes_read)
{
	char	*buffer;
	int		flag;

	flag = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (flag > 0 && !ft_strchr(bytes_read, '\n'))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		bytes_read = ft_strjoin(bytes_read, buffer);
		if (!bytes_read)
		{
			return (NULL);
		}
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_file(fd, bytes_read);
	if (!bytes_read)
		return (NULL);
	line = make_line(bytes_read);
	bytes_read = line_left(bytes_read);
	return (line);
}
