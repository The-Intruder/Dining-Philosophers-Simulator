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

static t_philo	*new_philo(size_t philo_index)
{
	t_philo	*philo;
	int		pthread_err;

	philo = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (philo == NULL)
		return (ft_perror(1, "new_philo", "Malloc Failure"), NULL);
	philo->next = NULL;
	philo->indx = philo_index;
	//pthread_err = pthread_create(&philo->fork, NULL, NULL, (void *)philo);
	pthread_err = pthread_mutex_init(&philo->fork, NULL);
	philo->prev = NULL;
	return (philo);
}

/* -------------------------------------------------------------------------- */

static void	add_philo(t_table *table, t_philo *new_philo)
{
	if (new_philo == NULL || table == NULL || table->head == NULL)
		return ;
	if (table->size == 0)
		table->head = new_philo;
	else
	{
		table->tail->next = new_philo;
		new_philo->prev = table->tail;
		table->head->prev = new_philo;
		new_philo->next = table->head;
	}
	table->tail = new_philo;
	table->size += 1;
}

/* -------------------------------------------------------------------------- */

t_table	*init_table(size_t philo_count)
{
	size_t	i;
	t_philo	*philo;
	t_table	*table;

	if (philo_count == 0)
		return (ft_perror(2, "init_table", "'philo_count' is Zero"), NULL);
	table = (t_table *)ft_calloc(1, sizeof(t_table));
	if (table == NULL)
		return (ft_perror(1, "init_table", "Malloc Failure"), NULL);
	i = 0;
	while (i++ < philo_count)
	{
		philo = new_philo(i);
		if (philo == NULL)
			return (free_table(table), NULL);
		add_philo(table, philo);
	}
	return (table);
}

/* -------------------------------------------------------------------------- */

void	iter_table(t_table *table, void (*function)(t_philo *))
{
	size_t	i;
	t_philo	*philo;

	if (table == NULL || function == NULL || table->head == NULL || \
		table->tail == NULL || table->size == 0)
		return (ft_perror(2, "iter_table", "Empty Argument"));
	i = 0;
	philo = table->head;
	while (i++ < table->size)
	{
		function(philo);
		philo = philo->next;
	}
}

/* -------------------------------------------------------------------------- */

void	free_table(t_table *table)
{
	t_philo	*node;
	t_philo	*tracer;
	size_t	i;

	tracer = table->head;
	i = 0;
	while (i++ < table->size)
	{
		node = tracer;
		tracer = tracer->next;
		free(node);
	}
}

/* -------------------------------------------------------------------------- */
