/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:12:28 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/03 10:12:32 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[FD_SIZE];
	char		*line;
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	error = ft_read_till_sep(fd, &buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (error == -1)
		return (ft_free(&buffer[fd]));
	if (error == 0)
	{
		line = ft_get_lines(buffer[fd]);
		ft_free(&buffer[fd]);
		if (line[0])
			return (line);
		free(line);
		return (NULL);
	}
	line = ft_get_lines(buffer[fd]);
	buffer[fd] = ft_new_buffer_start(buffer[fd]);
	return (line);
}
