/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:11 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_head.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

static void	*routine(void *ptr)
{
	t_philo	*philo_a;
	t_philo	*philo_b;
	size_t	i;

	philo_a = (t_philo *)ptr;
	i = philo_a->id;
	philo_b = &philo_a->table->philos[i];
	while (philo_a->state != DDD && philo_a->table->count_to_eat)
	{
		forks_action(philo_a, TAK);
		philo_eat(philo_a, philo_a->table->time_to_eat);
		forks_action(philo_a, PUT);
		print_safely(i, "is thinking", &philo_a->table->msg_mtx);
		philo_sleep(philo_a, philo_a->table->time_to_slp);
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */

static int	init_philo(t_table *table, size_t i)
{
	t_philo	*philo_a;
	int		pthread_err;

	philo_a = &(table->philos[i]);
	philo_a->table = (void *)table;
	philo_a->id = i + 1;
	philo_a->state = 0;
	pthread_err = pthread_create(&philo_a->ph_thrd, NULL, &routine, \
		(void *)philo_a);
	if (pthread_err != 0)
		return (-1);
	pthread_err = pthread_mutex_init(&philo_a->fork, NULL);
	if (pthread_err != 0)
		return (-1);
	pthread_err = pthread_detach(philo_a->ph_thrd);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_table(t_table *table, size_t philo_count)
{
	size_t	i;
	int		err;

	if (philo_count == 0)
		return (ft_perror(2, "'philo_count' is Zero"), -1);
	i = 0;
	table->philos = (t_philo *)ft_calloc(philo_count, sizeof(t_philo));
	if (table->philos == NULL)
		return (ft_perror(2, "Malloc Failure"), -1);
	err = pthread_mutex_init(&table->msg_mtx, NULL);
	if (err != 0)
		return (-1);
	while (i < philo_count)
	{
		err = init_philo(table, i++);
		if (err != 0)
			return (-1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
