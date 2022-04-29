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
	while (((t_philo *)ptr)->table->count_to_eat)
	{
		pthread_mutex_lock(&((t_philo *)ptr)->fork);
		pthread_mutex_lock(&((t_philo *)ptr)->table->philos[((t_philo *)ptr)->id + 1 % ((t_philo *)ptr)->table->philo_count].fork);
		print_safely(((t_philo *)ptr), "has taken a fork");
		print_safely(((t_philo *)ptr), "has taken a fork");
		print_safely(((t_philo *)ptr), "is eating");
		ft_usleep(((t_philo *)ptr)->table->time_to_eat);
		pthread_mutex_unlock(&((t_philo *)ptr)->table->philos[((t_philo *)ptr)->id + 1 % ((t_philo *)ptr)->table->philo_count].fork);
		pthread_mutex_unlock(&((t_philo *)ptr)->fork);
		print_safely((t_philo *)ptr, "is thinking");
		print_safely((t_philo *)ptr, "is sleeping");
		ft_usleep(((t_philo *)ptr)->table->time_to_slp);
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */

static int	init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
	{
		table->philos[i].table = table;
		table->philos[i].id = i;
		table->philos[i].state = 0;
	}
	i = -1;
	while (++i < table->philo_count)
		if (pthread_mutex_init(&table->philos[i].fork, NULL) != 0)
			return (ft_perror(2, "Mutex Init Failure"), -1);
	i = -1;
	while (++i < table->philo_count)
		if (pthread_create(&table->philos[i].ph_thrd, NULL, &routine, \
			(void *)&table->philos[i]) != 0)
			return (ft_perror(2, "Thread Creation Error"), -1);
	i = -1;
	while (++i < table->philo_count)
		if (pthread_detach(table->philos[i].ph_thrd) != 0)
			return (ft_perror(2, "Thread Detaching Error"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_table(t_table *table, int philo_count)
{
	table->philo_count = philo_count;
	table->philos = (t_philo *)ft_calloc(philo_count, sizeof(t_philo));
	if (table->philos == NULL)
		return (ft_perror(2, "Malloc Failure"), -1);
	if (pthread_mutex_init(&table->msg_mtx, NULL) != 0)
		return (ft_perror(2, "Mutex Init Failure"), -1);
	if (init_philos(table) != 0)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
