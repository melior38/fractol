/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:24:57 by asouchet          #+#    #+#             */
/*   Updated: 2022/09/10 12:28:26 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)ptr)[i] = value;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
    char dst[10];
    size_t n;
    char *ret;
    
    n = 10;
    ft_memset(dst, 'a', n);
    ret = ft_memset(dst, 'a', n);
    printf("%s\n", ret);
    return (0);
}*/
