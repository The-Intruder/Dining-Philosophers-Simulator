/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:11 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_head.h"

/* -------------------------------------------------------------------------- */

static void	take_forks(t_data *data)
{
	sem_wait();
}

/* -------------------------------------------------------------------------- */

static void	put_forks()
{
	
}

/* -------------------------------------------------------------------------- */

static void	*routine(t_data *data, int id)
{
	while (data->)
	{
		// take_forks(philo);
		// print_safely(philo, "is eating");
		// philo->last_meal_time = ft_get_usec_timestamp();
		// ft_usleep(data->time_to_eat);
		// philo->eat_count++;
		// put_forks(philo);
		// print_safely(philo, "is sleeping");
		// ft_usleep(data->time_to_slp);
		// print_safely(philo, "is thinking");
		// if (philo->eat_count == data->count_to_eat)
		// 	data->have_eaten += 1;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */

static int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		data->philos[i] = fork();
		if (data->philos[i] < 0)
			return (ft_perror(2, "Process Creation Failure"), -1);
		else if (data->philos[i] == 0)
			routine(data);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_data(t_data *data, int philo_count)
{
	data->philo_count = philo_count;
	data->philos = (pid_t *)ft_calloc(philo_count, sizeof(pid_t));
	if (data->philos == NULL)
		return (ft_perror(2, "Malloc Failure"), -1);
	if (init_philos(data) != 0)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
