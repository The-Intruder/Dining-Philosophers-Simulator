/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:21:58 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/17 21:56:39 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_head.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	destroy_data(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
		if (pthread_mutex_destroy(&table->philos[i].fork) != 0)
			return (-1);
	free(table->philos);
	return (0);
}
/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	ft_bzero(&table, sizeof(t_table));
	table.start_time = ft_get_time();
	if (init_args(&table, argc, argv) != 0)
		return (-1);
	i = -1;
	while (table.status == ON)
	{
		if (++i == table.philo_count)
			i = 0;
		if (ft_get_time() - table.philos[i].last_meal_time > table.time_to_die)
		{
			if (table.philos[i].stat == EAT)
				continue ;
			table.allow_print = OFF;
			table.status = OFF;
			printf("%-10lu %d died\n", \
				(ft_get_time() - table.start_time) / 1000, i + 1);
		}
		else if (table.count_to_eat != -1 && \
			table.have_eaten == table.philo_count)
		{
			table.allow_print = OFF;
			table.status = OFF;
		}
	}
	if (destroy_data(&table) != 0)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
