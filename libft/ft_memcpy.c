/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:33:47 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:17:12 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char		*str1;
	const char	*str2;
	size_t		a;

	str1 = (char *)dest;
	str2 = (char *)src;
	a = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (a < n)
	{
		str1[a] = str2[a];
		a++;
	}
	return (dest);
}
