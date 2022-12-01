/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_till_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:09:09 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/03 10:09:11 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_till_sep(int fd, char **buffer)
{
	char	*stash;
	int		n_byte;

	n_byte = 1;
	stash = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!stash)
		return (0);
	while (!ft_strchr(*buffer, '\n') && n_byte > 0)
	{
		n_byte = read(fd, stash, BUFFER_SIZE);
		if (n_byte < 0)
		{
			free(stash);
			return (-1);
		}
		if (n_byte == 0)
		{
			free(stash);
			return (0);
		}
		stash[n_byte] = '\0';
		*buffer = ft_gnljoin(*buffer, stash);
	}
	free(stash);
	return (n_byte);
}
