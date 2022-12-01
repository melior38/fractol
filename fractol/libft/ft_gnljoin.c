/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnljoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:05:06 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/03 10:05:11 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnljoin(char *buffer, char *stash)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	if (!buffer)
		buffer = ft_calloc(sizeof(char ), 1);
	if (!buffer || !stash)
		return (NULL);
	res = ft_calloc(sizeof(char ), (ft_strlen(buffer) + ft_strlen(stash) + 1));
	if (!res)
		return (NULL);
	if (buffer)
	{
		while (buffer[++i])
			res[i] = buffer[i];
	}
	while (stash[j])
	{
		res[i++] = stash[j++];
	}
	free(buffer);
	return (res);
}
