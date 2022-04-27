/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actvts.c                                     :+:      :+:    :+:   */
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

void	print_safely(t_table *table, size_t id, char *state)
{
	t_ulong	usec;

	pthread_mutex_lock(&table->msg_mtx);
	usec = ft_get_time_in_usec() - table->start_time;
	printf("%lu %zu %s\n", usec / 1000, id, state);
	pthread_mutex_unlock(&table->msg_mtx);
}

/* -------------------------------------------------------------------------- */

void	forks_action(t_philo *philo_a, t_philo *philo_b, int8_t state)
{
	if (state == TAK)
	{
		if (pthread_mutex_lock(&philo_a->fork) == 0)
			print_safely(philo_a->table, philo_a->id, "has taken a right fork");
		if (pthread_mutex_lock(&philo_b->fork) == 0)
			print_safely(philo_a->table, philo_a->id, "has taken a left fork");
	}
	else if (state == PUT)
	{
		if (pthread_mutex_unlock(&philo_a->fork) == 0)
			print_safely(philo_a->table, philo_a->id, "has put a right fork");
		if (pthread_mutex_unlock(&philo_b->fork) == 0)
			print_safely(philo_a->table, philo_a->id, "has put a left fork");
	}
}

/* -------------------------------------------------------------------------- */

void	philo_eat(t_philo *philo, useconds_t time_to_eat)
{
	print_safely(philo->table, philo->id, "is eating");
	philo->state &= EAT;
	usleep(time_to_eat);
	philo->state = 0;
}

/* -------------------------------------------------------------------------- */

void	philo_sleep(t_philo *philo, useconds_t time_to_sleep)
{
	print_safely(philo->table, philo->id, "is sleeping");
	philo->state &= SLP;
	usleep(time_to_sleep);
	philo->state = 0;
}

/* -------------------------------------------------------------------------- */
