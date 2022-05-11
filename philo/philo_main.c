/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:21:58 by mnaimi            #+#    #+#             */
/*   Updated: 2022/05/07 16:30:31 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_head.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	check_philos(t_table *table)
{
	int		i;
	t_philo	*philo;
	long	elapsed_time;

	i = -1;
	while (table->status == ON)
	{
		if (++i == table->philo_count)
			i = 0;
		philo = &table->philos[i];
		elapsed_time = ft_get_usec_timestamp() - philo->last_meal_time;
		if (elapsed_time > table->time_to_die || \
			table->have_eaten == table->philo_count)
		{
			table->allow_print = OFF;
			table->status = OFF;
			if (elapsed_time > table->time_to_die )
				printf("%6ld ms  %-2d died\n", (ft_get_usec_timestamp() - \
					table->start_time) / 1000, philo->id + 1);
			return (0);
		}
		if (usleep(100) != 0)
			return (-1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	destroy_data(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
		if (pthread_mutex_destroy(&table->philos[i].fork) != 0)
			return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_table	table;

	ft_bzero(&table, sizeof(t_table));
	table.start_time = ft_get_usec_timestamp();
	if (init_args(&table, argc, argv) != 0)
		return (-1);
	if (check_philos(&table) != 0)
		return (-1);
	// while (table.end_philos != table.philo_count)
	// 	usleep(10); // ???????????????????????????????????????????????????????
	if (destroy_data(&table) != 0)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
