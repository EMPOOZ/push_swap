/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:38:15 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:17:11 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *u, const void *b, size_t n)
{
	size_t					a;
	unsigned char			*f;
	const unsigned char		*x;

	a = 0;
	f = (unsigned char *)u;
	x = (unsigned char *)b;
	if (u == 0 && b == 0)
		return (0);
	if (b < u)
		while (++a <= n)
			f[n - a] = x[n - a];
	else
	{
		a = 0;
		while (n-- > 0)
		{
			f[a] = x[a];
			a++;
		}
	}
	return (u);
}
