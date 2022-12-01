/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:04:08 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/19 12:04:12 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

size_t	ft_trimcheck(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (ft_trimcheck(s1[start], set) && s1[start])
			start++;
	if (!end)
		return (ft_strdup(""));
	while (ft_trimcheck(s1[(end - 1)], set) && end > start)
			end--;
	res = malloc(sizeof(*s1) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
