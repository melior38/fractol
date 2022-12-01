/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:56:27 by asouchet          #+#    #+#             */
/*   Updated: 2022/08/18 09:16:29 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || \
	(c >= 97 && c <= 122) || \
	(c >= 48 && c <= 57))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf ("ERROR"));

	printf("%d\n", ft_isalnum(atoi(av[1])));
}*/
