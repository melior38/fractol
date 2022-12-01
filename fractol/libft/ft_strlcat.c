/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:25:21 by asouchet          #+#    #+#             */
/*   Updated: 2022/09/10 23:10:56 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	t;

	if (ft_strlen(dest) >= n)
		return (ft_strlen(src) + n);
	i = 0;
	t = ft_strlen(dest);
	while (t + i < n - 1 && src[i])
	{
		dest[t + i] = src[i];
		i++;
	}
	dest[t + i] = '\0';
	return (t + ft_strlen(src));
}
