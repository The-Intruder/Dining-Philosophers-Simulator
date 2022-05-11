/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/05/07 16:33:33 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_head.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

long	ft_get_usec_timestamp(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

/* -------------------------------------------------------------------------- */

void	ft_usleep(long time_to_sleep)
{
	long	time;

	time = ft_get_usec_timestamp();
	while (ft_get_usec_timestamp() - time < time_to_sleep)
		usleep(10);
}

/* -------------------------------------------------------------------------- */

void	print_safely(t_philo *philo, char *action)
{
	long	time;

	pthread_mutex_lock(&philo->table->msg_mtx);
	time = ft_get_usec_timestamp() - philo->table->start_time;
	if (philo->table->allow_print == ON)
		printf("%6ld ms  %-2d %s\n", time / 1000, philo->id + 1, action);
	pthread_mutex_unlock(&philo->table->msg_mtx);
}

/* -------------------------------------------------------------------------- */

void	ft_perror(int type, char *cause)
{
	if (type == 1)
		write(2, RED"\n\033[4mError\033[0m\t", 20);
	else if (type == 2)
		write(2, YEL"\n\033[4mWarning\033[0m\t"NNN, 22);
	write(2, cause, ft_strlen(cause));
	write(2, "\n\n", 2);
	if (type == 2)
		usleep(999999);
}

/* -------------------------------------------------------------------------- */
