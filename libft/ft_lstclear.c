/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:18:13 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:17:26 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst2;
	t_list	*lst3;

	if (!lst || !del)
		return ;
	lst2 = *lst;
	while (lst2)
	{
		lst3 = lst2->next;
		if (lst2->content)
			del(lst2->content);
		free(lst2);
		lst2 = lst3;
	}
	*lst = NULL;
}
