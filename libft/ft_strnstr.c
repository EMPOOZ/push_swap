/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:20:20 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:18:26 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	c;
	size_t	m;

	c = 0;
	while (haystack[c] && c < n)
	{
		m = 0;
		while (haystack[c + m] && needle[m] && c + m < n
			&& haystack[c + m] == needle[m])
			m++;
		if (!needle[m])
			return ((char *)(haystack + c));
		c++;
	}
	if (!haystack || !needle[0])
		return ((char *)haystack);
	if (!haystack || !needle)
		return (NULL);
	return (NULL);
}
