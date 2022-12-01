/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_buffer_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:10:36 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/03 10:10:38 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_buffer_start(char *buffer)
{
	size_t	i;
	size_t	l;
	char	*res;

	l = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	res = malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (!res)
		return (0);
	while (buffer[i])
	{
		res[l] = buffer[i];
		i++;
		l++;
	}
	res[l] = '\0';
	free(buffer);
	return (res);
}
