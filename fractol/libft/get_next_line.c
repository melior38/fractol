/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:11:01 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/03 10:11:50 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	error = ft_read_till_sep(fd, &buffer);
	if (!buffer)
		return (NULL);
	if (error == -1)
		return (ft_free(&buffer));
	if (error == 0)
	{
		line = ft_get_lines(buffer);
		ft_free(&buffer);
		if (line[0])
			return (line);
		free(line);
		return (NULL);
	}
	line = ft_get_lines(buffer);
	buffer = ft_new_buffer_start(buffer);
	return (line);
}
