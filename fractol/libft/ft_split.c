/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:25:45 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/20 14:25:47 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/* 
ft_count_sep gere la separation des mots
ft_strlen_until_sep gere les tailles de malloc
ft_split gere les dernier cas non gerer par ft_count_sep

 */
size_t	ft_sep_check(char s, char sep)
{
	if (s == sep)
		return (1);
	return (0);
}

size_t	ft_len_til_sep(char const *s, char sep)
{
	size_t	i;

	i = 0;
	while (s[i] != sep && s[i])
		i++;
	return (i);
}

size_t	ft_count_sep(char const *s, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == sep)
			while (ft_sep_check(s[i], sep))
				i++;
		else
		{
			words++;
			while (s[i] && !ft_sep_check(s[i], sep))
				i++;
		}
	}
	return (words);
}

//char	*ft_substr(char const *s, unsigned int start, size_t len)

char	**ft_split(char const *s, char sep)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (ft_count_sep(s, sep) + 1));
	if (!res)
		return (0);
	while (i < ft_count_sep(s, sep))
	{
		if (s[j] == sep)
			while (ft_sep_check(s[j], sep))
				j++;
		else
		{
			res[i] = ft_substr(s, (unsigned int)j, ft_len_til_sep(&s[j], sep));
			while (s[j] && !ft_sep_check(s[j], sep))
				j++;
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
