/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:12:40 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/21 20:20:51 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	ft_digit_count(int nb)
{
	size_t	count;

	count = 0;
	if (nb == -2147483648)
	{
		count = 11;
		return (count);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	if (nb < 10)
		count++;
	return (count);
}

char	*ft_tab_fill(int n, char *str)
{
	int	i;

	i = ft_digit_count(n);
	i = i - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		str[i] = (48 + (n % 10));
		n = n / 10;
		i--;
	}
	if (n < 10)
		str[i] = (n + 48);
	return (str);
}

char	*ft_min_int(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = ft_digit_count(n);
	res = ft_calloc(sizeof(char), (i + 1));
	if (!res)
		return (0);
	if (n != -2147483648)
		ft_tab_fill(n, res);
	else
		ft_min_int(res);
	return (res);
}
