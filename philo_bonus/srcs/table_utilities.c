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

static void	perform_action_on_forks(t_data *data, int action)
{
	if (action == TAKE_FORKS)
	{
		sem_wait(data->forks_sem);
		print_safely(data, "has taken a fork");
		sem_wait(data->forks_sem);
		print_safely(data, "has taken a fork");
	}
	else if (action == PUT_FORKS)
	{
		sem_post(data->forks_sem);
		sem_post(data->forks_sem);
	}
}

/* -------------------------------------------------------------------------- */

static void	*check_death(void *ptr)
{
	t_data	*data;
	long	elapsed_time;

	data = (t_data *)(ptr);
	while (true)
	{
		elapsed_time = ft_get_usec_timestamp() - data->last_meal_time;
		if (elapsed_time > data->time_to_die)
		{
			sem_wait(data->print_sem);
			printf("%6ld ms  %-2d has died\n", (ft_get_usec_timestamp() \
				- data->start_time) / 1000, data->id + 1);
			exit(HAS_DIED);
		}
		usleep(100);
	}
}

/* -------------------------------------------------------------------------- */

static void	routine(t_data *data)
{
	if (pthread_create(&data->monitor_thrd, NULL, &check_death, \
		(void *)data) != 0)
		exit(HAS_CRASHED);
	while (true)
	{
		perform_action_on_forks(data, TAKE_FORKS);
		print_safely(data, "is eating");
		data->last_meal_time = ft_get_usec_timestamp();
		ft_usleep(data->time_to_eat);
		perform_action_on_forks(data, PUT_FORKS);
		data->eat_count++;
		print_safely(data, "is sleeping");
		ft_usleep(data->time_to_slp);
		print_safely(data, "is thinking");
		if (data->eat_count == data->count_to_eat)
			exit(HAS_EATEN);
	}
}

/* -------------------------------------------------------------------------- */

static int	init_philos(t_data *data)
{
	int	i;

	data->start_time = ft_get_usec_timestamp();
	data->eat_count = 0;
	i = -1;
	while (++i < data->philo_count)
	{
		data->philos_procs[i] = fork();
		if (data->philos_procs[i] < 0)
			return (ft_perror(data, 1, "Process Creation Failure"), \
			kill_child_procs(data), -1);
		else if (data->philos_procs[i] == 0)
		{
			free(data->philos_procs);
			data->id = i;
			data->last_meal_time = ft_get_usec_timestamp();
			routine(data);
		}
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_data(t_data *data)
{
	int	philo_count;

	philo_count = data->philo_count;
	if (philo_count > SEM_VALUE_MAX)
		return (ft_perror(data, 1, "Philos count way too big"), -1);
	sem_unlink(FORKS_CUSTOM_SEM);
	data->forks_sem = sem_open(FORKS_CUSTOM_SEM, O_CREAT, \
		(S_IRUSR | S_IWUSR), philo_count);
	if (data->forks_sem == SEM_FAILED)
		return (ft_perror(data, 1, "Semaphore Failure"), -1);
	sem_unlink(PRINT_CUSTOM_SEM);
	data->print_sem = sem_open(PRINT_CUSTOM_SEM, O_CREAT, \
		(S_IRUSR | S_IWUSR), 1);
	if (data->print_sem == SEM_FAILED)
		return (ft_perror(data, 1, "Semaphore Failure"), -1);
	data->philos_procs = (pid_t *)ft_calloc(philo_count, sizeof(pid_t));
	if (data->philos_procs == NULL)
		return (ft_perror(data, 1, "Malloc Failure"), -1);
	if (init_philos(data) != 0)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */
