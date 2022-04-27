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

void	print_safely(size_t id, char *state, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	printf("%zu %s\n", id, state);
	pthread_mutex_unlock(mutex);
}

/* -------------------------------------------------------------------------- */

void	forks_action(t_philo *philo_a, int8_t state)
{
	t_philo	*philo_b;
	size_t	i;

	i = philo_a->id;
	philo_b = &philo_a->table->philos[i];
	if (state == TAK)
	{
		pthread_mutex_lock(&philo_a->fork);
		print_safely(i, "has taken a fork", &philo_a->table->msg_mtx);
		pthread_mutex_lock(&philo_b->fork);
		print_safely(i, "has taken a fork", &philo_a->table->msg_mtx);
	}
	else if (state == PUT)
	{
		pthread_mutex_unlock(&philo_a->fork);
		pthread_mutex_unlock(&philo_b->fork);
	}
}

/* -------------------------------------------------------------------------- */

void	philo_eat(t_philo *philo, useconds_t time_to_eat)
{
	philo->state &= EAT;
	print_safely(philo->id, "is eating", &philo->table->msg_mtx);
	usleep(time_to_eat);
	philo->state = 0;
}

/* -------------------------------------------------------------------------- */

void	philo_sleep(t_philo *philo, useconds_t time_to_sleep)
{
	philo->state &= SLP;
	print_safely(philo->id, "is sleeping", &philo->table->msg_mtx);
	usleep(time_to_sleep);
	philo->state = 0;
}

/* -------------------------------------------------------------------------- */

void	philo_think(t_philo *philo, useconds_t time_to_think)
{
	philo->state &= THK;
	print_safely(philo->id, "is thinking", &philo->table->msg_mtx);
	usleep(time_to_think);
	philo->state = 0;
}

/* -------------------------------------------------------------------------- */
