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

int	philo_eat(t_philo *philo, t_uint time_to_eat)
{
	int	err;

	philo->state &= EAT;
	err = usleep(time_to_eat);
	philo->state = 0;
	if (err != 0)
		return (ft_perror(1, "usleep failure"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_sleep(t_philo *philo, t_uint time_to_sleep)
{
	int	err;

	philo->state &= SLP;
	err = usleep(time_to_sleep);
	philo->state = 0;
	if (err != 0)
		return (ft_perror(1, "usleep failure"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_think(t_philo *philo, t_uint time_to_think)
{
	int	err;

	philo->state &= THK;
	err = usleep(time_to_think);
	philo->state = 0;
	if (err != 0)
		return (ft_perror(1, "usleep failure"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_take_fork(pthread_mutex_t *fork)
{
	int	err;

	err = pthread_mutex_lock(fork);
	if (err != 0)
		return (ft_perror(1, "Unsuccessful Mutex Locking"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_put_fork(pthread_mutex_t *fork)
{
	int	err;

	err = pthread_mutex_unlock(fork);
	if (err != 0)
		return (ft_perror(1, "Unsuccessful Mutex Unlocking"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */
