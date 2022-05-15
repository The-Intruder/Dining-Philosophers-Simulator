/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:21:58 by mnaimi            #+#    #+#             */
/*   Updated: 2022/05/07 16:30:31 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_head.h"

/* -------------------------------------------------------------------------- */

void	kill_child_procs(t_data *data)
{
	sem_close(data->forks_sem);
	sem_unlink(FORKS_CUSTOM_SEM);
	sem_close(data->print_sem);
	sem_unlink(PRINT_CUSTOM_SEM);
	free(data->philos_procs);
	write(1, BLK, 5);
	kill(0, SIGKILL);
}

/* -------------------------------------------------------------------------- */

static void	check_child_procs(t_data *data)
{
	pid_t	wp_ret_val;
	int		wp_stat;
	int		has_eaten;

	has_eaten = 0;
	while (true)
	{
		if (has_eaten == data->philo_count)
			return ;
		wp_ret_val = waitpid(-1, &wp_stat, 0);
		if (WIFEXITED(wp_stat) != 0)
		{
			if (WEXITSTATUS(wp_stat) == HAS_DIED)
				break ;
			else if (WEXITSTATUS(wp_stat) == HAS_EATEN)
				has_eaten += 1;
			continue ;
		}
		break ;
	}
	kill_child_procs(data);
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (init_args(&data, argc, argv) != 0)
		return (-1);
	if (init_data(&data) != 0)
		return (-1);
	check_child_procs(&data);
	return (0);
}

/* -------------------------------------------------------------------------- */
