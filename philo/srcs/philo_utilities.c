/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilities.c                                  :+:      :+:    :+:   */
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

t_ulong	ft_get_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((t_ulong)((time.tv_sec * 1000000) + time.tv_usec));
}

/* -------------------------------------------------------------------------- */

void	ft_usleep(useconds_t time_to_sleep)
{
	t_ulong	time;

	time = ft_get_time();
	while (ft_get_time() - time < time_to_sleep)
		;
}

/* -------------------------------------------------------------------------- */

void	print_safely(t_philo *philo, char *action)
{
	if (philo->table->allow_print == OFF)
		return ;
	pthread_mutex_lock(&philo->table->msg_mtx);
	printf("%-10lu %d %s\n", (ft_get_time() - philo->table->start_time) \
		/ 1000, philo->id + 1, action);
	pthread_mutex_unlock(&philo->table->msg_mtx);
}

/* -------------------------------------------------------------------------- */

void	ft_perror(int type, char *cause)
{
	if (type == 1)
		write(2, RED"\033[4m\nError\033[0m\t", 20);
	else if (type == 2)
		write(2, YEL"\nWarning"NNN, 17);
	write(2, cause, ft_strlen(cause));
	write(2, "\n\n", 2);
}

/* -------------------------------------------------------------------------- */