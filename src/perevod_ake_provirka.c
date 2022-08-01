/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perevod_ake_provirka.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:49:36 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/26 15:36:32 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_mass(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
}

void	ft_atoi_help(int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("max int\n", 1);
		exit (1);
	}
	if (flag == 1)
	{
		ft_putstr_fd("min int\n", 1);
		exit (1);
	}
}

int	ft_atoi(const char *str)
{
	long long		c;
	long long		f;
	unsigned int	m;

	f = 0;
	c = 1;
	m = 0;
	while (str[f] == '\t' || str[f] == '\n' || str[f] == '\v'
		|| str[f] == '\f' || str[f] == '\r' || str[f] == ' ' || str[f] == '"')
		f++;
	if (str[f] == '+' || str[f] == '-')
		if (str[f++] == '-')
			c *= -1;
	while ((str[f] >= '0') && (str[f] <= '9'))
		m = (m * 10) + (str[f++] - '0');
	c *= m;
	if (c >= 2147483648)
		ft_atoi_help(0);
	if (c <= -2147483649)
		ft_atoi_help(1);
	return (c);
}

int	provirka(int argc, char **argv)
{
	int	i;
	int	i1;

	i1 = 0;
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		i1 = 0;
		while (argv[i][i1])
		{
			if (argv[i][i1] == '-' || argv[i][i1] == '+')
				i1++;
			if (argv[i][i1] < '0' || argv[i][i1] > '9')
				return (1);
			i1++;
		}
		i++;
	}
	return (0);
}

t_stack	*perevod_ake_provirka(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		c;

	c = 0;
	stack = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		c = 1;
	}
	i = provirka(argc, argv);
	if (i == 1)
	{
		ft_putstr_fd("invalid value entered\n", 1);
		exit (1);
	}
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
		ft_lstadd_back1(&stack, (ft_atoi(argv[i++])), 0);
	if (c == 1)
		free_mass(argv);
	return (stack);
}
