/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:11 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../philo_head.h"

/* -------------------------------------------------------------------------- */

void	philo_eat(t_philo *philo, t_uint time_to_eat)
{
	philo->actn &= EAT;
	usleep(time_to_eat);
}

/* -------------------------------------------------------------------------- */

void	philo_sleep(t_philo *philo, t_uint time_to_sleep)
{
	philo->actn &= SLP;
	usleep(time_to_sleep);
}

/* -------------------------------------------------------------------------- */

void	philo_think(t_philo *philo, t_uint time_to_think)
{
	philo->actn &= THK;
	usleep(time_to_think);
}

/* -------------------------------------------------------------------------- */

void	philo_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	err;

	err = pthread_mutex_lock(fork);
	if (err != 0)
		ft_perror(1, "philo_take_fork", "unsuccessful mutex locking");
}

/* -------------------------------------------------------------------------- */

void	philo_put_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	err;

	err = pthread_mutex_unlock(fork);
	if (err != 0)
		ft_perror(1, "philo_put_fork", "unsuccessful mutex unlocking");
}

/* -------------------------------------------------------------------------- */
