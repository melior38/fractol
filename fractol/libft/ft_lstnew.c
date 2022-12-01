/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:02:23 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/27 14:02:26 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
typedef struct s_pos
{
	int x;
	int y;
}	t_pos;



t_pos a;

a.x = 1;
a.y = 2;

t_pos *b;

b = &a;


(*b).x = 1;
b->x = 2;


new->next->next->next->content;
(*(*(*new).next).next).content
*/