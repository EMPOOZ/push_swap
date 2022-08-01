/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:19:31 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/26 16:11:42 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pushswap.h"

int	check_commands3(char *command, t_data *data)
{
	if (ft_strncmp(command, "pb", 100) == 0)
	{
		push(&(data->a), &(data->b), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "rra", 100) == 0)
	{
		rra(&(data->a), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "rrb", 100) == 0)
	{
		ra(&(data->b), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "rrr", 100) == 0)
	{
		rrr(data, NULL);
		return (1);
	}
	return (0);
}

int	check_commands2(char *command, t_data *data)
{
	if (ft_strncmp(command, "ra", 100) == 0)
	{
		ra(&(data->a), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "rb", 100) == 0)
	{
		ra(&(data->b), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "rr", 100) == 0)
	{
		rr(data, NULL);
		return (1);
	}
	else if (ft_strncmp(command, "pa", 100) == 0)
	{
		push(&(data->b), &(data->a), NULL);
		return (1);
	}
	return (check_commands3 (command, data));
}

int	check_comands(char *command, t_data *data)
{
	if (ft_strncmp(command, "sa", 100) == 0)
	{
		sa(&(data->a), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "sb", 100) == 0)
	{
		sa(&(data->b), NULL);
		return (1);
	}
	else if (ft_strncmp(command, "ss", 100) == 0)
	{
		ss(data, NULL);
		return (1);
	}
	return (check_commands2 (command, data));
}

char	**hand_sorting(void)
{
	char	*command;
	char	**commands;
	char	*str;
	int		i;

	i = 0;
	command = malloc(1);
	command[0] = '\0';
	str = malloc(1);
	while (str != 0)
	{
		free(str);
		str = get_next_line(0);
		if (str != 0)
			command = ft_strjoin(command, str);
		i++;
	}
	free(str);
	commands = ft_split(command, '\n');
	free(command);
	return (commands);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**commands;

	if (argc < 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	data->a = NULL;
	data->b = NULL;
	data->a = perevod_ake_provirka(argc, argv);
	provirka2 (data);
	commands = hand_sorting();
	help_main (commands, data);
	if (sort_check(data->a) == 0 && ft_lstsize1(data->b) == 0)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	free_data(data);
	free_mass(commands);
	return (0);
}
