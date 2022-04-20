/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pars.c                                        :+:      :+:    :+:   */
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

void	init_table_vars(t_table *table, int64_t value, size_t var_numb)
{
	if (var_numb == 2)
		table->time_to_die = value;
	else if (var_numb == 3)
		table->time_to_eat = value;
	else if (var_numb == 4)
		table->time_to_slp = value;
	else if (var_numb == 5)
		table->count_to_eat = value;
}

/* -------------------------------------------------------------------------- */

static char	**join_split_args(int argc, char **argv)
{
	size_t	i;
	void	*ptr;
	char	*jnd_args;
	char	**spltd_args;

	i = 1;
	jnd_args = ft_strdup(argv[i]);
	if (jnd_args == NULL || *jnd_args == '\0')
		return (ft_free((void **)&jnd_args), NULL);
	while (++i < (size_t)argc)
	{
		ptr = jnd_args;
		jnd_args = ft_strjoin(jnd_args, argv[i], ' ');
		ft_free((void **)&ptr);
		if (jnd_args == NULL || *jnd_args == '\0')
			return (ft_free((void **)&jnd_args), NULL);
	}
	spltd_args = ft_split(jnd_args, ' ');
	if (spltd_args == NULL || *spltd_args == NULL)
		ft_free((void **)&spltd_args);
	return (spltd_args);
}

/* -------------------------------------------------------------------------- */

static int	valid_arg(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if ((i == 0 && arg[i] != '+' && !ft_isdigit(arg[i])) || \
			(i != 0 && !ft_isdigit(arg[i++])))
			return (ft_perror(1, "valid_arg", "Invalid Argument"), 0);
		++i;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */

t_table	*init_args_to_table(int argc, char **argv)
{
	char	**new_argv;
	t_table	*table;
	int64_t	value;
	size_t	i;

	if (argc <= 1)
		return (ft_perror(1, "init_arg...", "Not enough arguments"), NULL);
	new_argv = join_split_args(argc, argv);
	i = 0;
	table = NULL;
	while (new_argv[i] && valid_arg(new_argv[i]))
	{
		if (i >= 5)
			return (ft_perror(1, "init_arg...", "Too many Arguments"), NULL);
		value = ft_custom_atoll(new_argv[i++]);
		if (value <= 0)
			return (ft_perror(1, "init_args_to_table", "Invalid Argument"), \
				free_table(table), free_2d_arr(new_argv), NULL);
		else if (i == 1)
			table = init_table((size_t)value);
		else
			init_table_vars(table, value, i);
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */
