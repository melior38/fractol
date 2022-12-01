/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:35:17 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/17 14:35:19 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
// alloue un nouveau start sur une string const char. 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	res = (char *)malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		if (j < len && i >= start)
		{
			res[j] = s[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
