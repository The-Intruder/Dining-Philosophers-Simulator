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

void	print_safely(t_data *data, char *action)
{
	long	time;

	sem_wait(data->print_sem);
	time = ft_get_usec_timestamp() - data->start_time;
	printf("%6ld ms  %-2d %s\n", time / 1000, data->id + 1, action);
	sem_post(data->print_sem);
}

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

void	ft_perror(t_data *data, int type, char *cause)
{
	sem_wait(data->print_sem);
	if (type == 1)
		write(2, RED"\n\033[4mError:\033[0m\t"NNN, 25);
	else if (type == 2)
		write(2, YEL"\n\033[4mWarning:\033[0m\t"NNN, 27);
	write(2, cause, ft_strlen(cause));
	write(2, "\n\n", 2);
}

/* -------------------------------------------------------------------------- */
