/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:11 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_head.h"

/* -------------------------------------------------------------------------- */

t_ulong	ft_get_time_in_usec(void)
{
	t_timeval	time;
	t_ulong		usec_time;

	gettimeofday(&time, NULL);
	usec_time = (time.tv_sec * 1000000) + time.tv_usec;
	return (usec_time);
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

void	ft_usleep(useconds_t usec_to_sleep)
{
	t_ulong	time_in_usec;

	time_in_usec = ft_get_time_in_usec();
	while (ft_get_time_in_usec() - time_in_usec > usec_to_sleep)
		usleep(usec_to_sleep / 10);
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