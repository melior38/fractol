/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:26:31 by asouchet          #+#    #+#             */
/*   Updated: 2022/09/10 21:45:46 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		*(ptr++) = '\0';
	}
}
/*
int	main(int ac, char **av)
{
	(void) ac;
	unsigned char *test = "Rick et Morty c le feu";

	ft_bzero (test, atoi(av[1]));
	printf ("%s\n", test);
	return (0);	
}*/
