/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:39:30 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/01 17:53:15 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + str[i] - 48);
		i++;
	}
	return (res * neg);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	printf("atoi: %d\n", atoi(av[1]));
	printf("ft_atoi: %d \n", ft_atoi(av[1]));
	return (0);
}*/