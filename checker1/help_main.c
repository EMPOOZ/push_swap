/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:00:44 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/26 16:03:23 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pushswap.h"

void	help_main(char **commands, t_data *data)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		if (check_comands(commands[i], data) == 0)
		{
			free_data(data);
			free_mass(commands);
			ft_putstr_fd("Error", 1);
			exit (1);
		}
		i++;
	}
}
