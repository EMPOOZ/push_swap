/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:41:49 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:17:30 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	revstr(char *str1)
{
	int	i;
	int	len;
	int	temp;

	len = ft_strlen(str1);
	i = 0;
	while (i < (len / 2))
	{
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
		i++;
	}
}

char	*vid(int c)
{
	char	*v;
	long	i;

	i = 0;
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	v = malloc(i + 2);
	if (!v)
		return (0);
	return (v);
}

char	*ft_itoa(int n)
{
	char		*p;
	size_t		i;
	long long	y;

	i = 0;
	y = n;
	p = vid(n);
	if (!p)
		return (0);
	if (y < 0)
		y *= -1;
	while (y != 0)
	{
		p[i++] = (y % 10) + '0';
		y /= 10;
	}
	if (n < 0)
		p[i] = '-';
	if (i == 0)
		p[i] = '0';
	if (n <= 0)
		p[++i] = '\0';
	p[i] = '\0';
	revstr(p);
	return (p);
}
