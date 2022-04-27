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

// int	death_chrono(useconds_t start_time, useconds_t time_of_death)
// {

// }

/* -------------------------------------------------------------------------- */

static void	*routine(void *ptr)
{
	t_timeval	strt_curnt_time[2];
	t_philo		*philo_a;
	t_philo		*philo_b;
	t_ulong		i;
	t_ulong		j;

	gettimeofday(&strt_curnt_time[0], NULL);
	philo_a = (t_philo *)ptr;
	i = philo_a->id;
	j = i + 1;
	printf("i: %lu; j: %lu\n", i, j);
	j = (i + 1) % philo_a->table->philo_count;
	philo_b = &philo_a->table->philos[j];
	while (philo_a->state != DDD && philo_a->table->count_to_eat)
	{
		forks_action(philo_a, philo_b, TAK);
		philo_eat(philo_a, philo_a->table->time_to_eat);
		forks_action(philo_a, philo_b, PUT);
		print_safely(philo_a->table, i, "is thinking");
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
	philo_a->id = i;
	philo_a->state = 0;
	pthread_err = pthread_create(&philo_a->ph_thrd, NULL, &routine, \
		(void *)philo_a);
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
	table->philos = (t_philo *)ft_calloc(philo_count, sizeof(t_philo));
	if (table->philos == NULL)
		return (ft_perror(2, "Malloc Failure"), -1);
	err = pthread_mutex_init(&table->msg_mtx, NULL);
	if (err != 0)
		return (-1);
	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&table->philos[i++].fork, NULL) != 0)
			return (-1);
	}
	i = 0;
	while (i < philo_count)
	{
		err = init_philo(table, i++);
		if (err != 0)
			return (-1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
