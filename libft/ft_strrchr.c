/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:24:26 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:28 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)&s[i]);
	while (s[--i] != (unsigned char)c)
	{
		if (i <= 0)
			return (0);
		if (!s[i])
			return (0);
	}
	return ((char *)&s[i]);
}
