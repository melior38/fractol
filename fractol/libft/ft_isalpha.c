/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:28:59 by asouchet          #+#    #+#             */
/*   Updated: 2022/08/18 09:15:45 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || \
	(c >= 97 && c <= 122))
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

	printf("%d\n", ft_isalpha(atoi(av[1])));
}*/
