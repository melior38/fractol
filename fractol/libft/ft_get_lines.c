/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:10:08 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/03 10:10:11 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_lines(char	*buffer)
{
	size_t	i;
	size_t	l;
	char	*line;

	i = 0;
	l = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char ) * (i + 1));
	while (i > l)
	{
		line[l] = buffer[l];
		l++;
	}
	line[l] = '\0';
	return (line);
}
