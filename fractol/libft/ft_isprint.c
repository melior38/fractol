/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:07:59 by asouchet          #+#    #+#             */
/*   Updated: 2022/08/18 09:15:12 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	printf("%d\n", ft_isprint(atoi(av[1])));
}*/
