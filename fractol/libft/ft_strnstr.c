/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:19:33 by asouchet          #+#    #+#             */
/*   Updated: 2022/09/11 11:19:35 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#define UC unsigned char

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen((char *)src);
	if (((UC *)src)[0] == 0)
		return (&((char *)dest)[i]);
	while (((UC *)dest)[i] && i < n)
	{
		if (((UC *)dest)[i] == ((UC *)src)[0])
		{
			if (i + srclen <= n && srclen <= n && \
				!ft_strncmp(&((char *)dest)[i], (char *)src, srclen))
			{
				return (&((char *)dest)[i]);
			}
		}
		i++;
	}
	return (0);
}
