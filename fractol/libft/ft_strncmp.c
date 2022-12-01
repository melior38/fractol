/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:53:43 by asouchet          #+#    #+#             */
/*   Updated: 2022/08/17 21:21:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s1[i] == s2[j] && (s1[i] && s2[i]))
		{
			i++;
			j++;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ag, char **av)
{

	(void) ag;
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	printf("%d\n", strncmp(av[1], av[2], atoi(av[3])));
	return (0);
}*/
