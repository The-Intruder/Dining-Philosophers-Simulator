/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
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

/* -------------------------------------------------------------------------- */

static void	*routine(void *ptr)
{
	ptr = NULL;
	while (1)
		;
	return (NULL);
}

/* -------------------------------------------------------------------------- */

static int	init_philo(t_table *table, size_t i)
{
	int		pthread_err;
	t_philo	*philo;
	t_philo	*next_philo;
	int		nxt_indx;

	nxt_indx = (i + 1) % table->philo_count;
	philo = &(table->philos[i]);
	next_philo = &(table->philos[nxt_indx]);
	philo->table = (void *)table;
	philo->state = 0;
	philo->fork_b = &(next_philo->fork_a);
	pthread_err = pthread_create(&philo->philo_th, NULL, &routine, \
		(void *)table);
	if (pthread_err != 0)
		return (-1);
	pthread_err = pthread_mutex_init(&philo->fork_a, NULL);
	if (pthread_err != 0)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_table(t_table *table, size_t philo_count)
{
	size_t	i;
	int		err;

	if (philo_count == 0)
		return (ft_perror(2, "'philo_count' is Zero"), -1);
	i = 0;
	table->philos = (t_philo *)ft_calloc(philo_count, sizeof(t_philo));
	if (table->philos == NULL)
		return (ft_perror(2, "Malloc Failure"), -1);
	printf("Here!!!%zu\n", philo_count);
	while (i < philo_count)
	{
		err = init_philo(table, i++);
		if (err != 0)
			return (-1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
