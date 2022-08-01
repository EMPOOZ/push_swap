/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:18:54 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:17:21 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*y;
	t_list	*q;

	y = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		q = ft_lstnew(f(lst->content));
		if (!q)
		{
			del(q);
		}
		ft_lstadd_back(&y, q);
		lst = lst->next;
	}
	return (y);
}
