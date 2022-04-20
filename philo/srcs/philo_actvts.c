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

	philo->stat &= EAT;
	err = usleep(time_to_eat);
	philo->stat = 0;
	if (err != 0)
		return (ft_perror(1, "philo_think", "usleep failure"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_sleep(t_philo *philo, t_uint time_to_sleep)
{
	int	err;

	philo->stat &= SLP;
	err = usleep(time_to_sleep);
	philo->stat = 0;
	if (err != 0)
		return (ft_perror(1, "philo_think", "usleep failure"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_think(t_philo *philo, t_uint time_to_think)
{
	int	err;

	philo->stat &= THK;
	err = usleep(time_to_think);
	philo->stat = 0;
	if (err != 0)
		return (ft_perror(1, "philo_think", "usleep failure"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_take_fork(pthread_mutex_t *fork)
{
	int	err;

	err = pthread_mutex_lock(fork);
	if (err != 0)
		return (ft_perror(1, "philo_take_fork", \
			"Unsuccessful Mutex Locking"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	philo_put_fork(pthread_mutex_t *fork)
{
	int	err;

	err = pthread_mutex_unlock(fork);
	if (err != 0)
		return (ft_perror(1, "philo_put_fork", \
			"Unsuccessful Mutex Unlocking"), -1);
	return (0);
}

/* -------------------------------------------------------------------------- */
