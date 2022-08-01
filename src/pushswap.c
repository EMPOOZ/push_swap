/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:49:46 by tconwy            #+#    #+#             */
/*   Updated: 2021/11/26 15:38:16 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	data_init(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	data_init(data);
	data->a = perevod_ake_provirka(argc, argv);
	provirka2 (data);
	sorting(data);
	free_data (data);
	return (0);
}
