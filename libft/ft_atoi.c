/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:32:19 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/02 20:17:40 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	long long			i;
	long long			f;
	unsigned int		m;

	m = 0;
	f = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			f *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		m = m * 10 + str[i++] - 48;
	f *= m;
	if (f >= 2147483648)
		return (-1);
	if (f <= -2147483649)
		return (0);
	return (f);
}
