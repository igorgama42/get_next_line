/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:54:21 by igama             #+#    #+#             */
/*   Updated: 2023/12/02 19:46:10 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	fd = foo.txt;
	if (fd < 0)
		return ("error");
	open(fd, O_RDONLY | O_EXCL);
}
