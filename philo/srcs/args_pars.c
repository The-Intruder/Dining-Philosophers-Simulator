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

static char	**refactor_args(int argc, char **argv)
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
	ft_free((void **)&jnd_args);
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
			(i != 0 && !ft_isdigit(arg[i])))
			return (0);
		++i;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */

static int	init_vars(t_table *table, int64_t value, size_t var_numb)
{
	int	err;

	err = 0;
	if (var_numb == 1)
		err = init_table(table, (size_t)value);
	else if (var_numb == 2)
		table->time_to_die = value;
	else if (var_numb == 3)
		table->time_to_eat = value;
	else if (var_numb == 4)
		table->time_to_slp = value;
	else if (var_numb == 5)
		table->count_to_eat = value;
	return (err);
}

/* -------------------------------------------------------------------------- */

int	init_args(t_table *table, int argc, char **argv)
{
	char	**new_argv;
	int32_t	value;
	int		err;
	size_t	i;

	if (argc <= 1)
		return (ft_perror(1, "Not enough arguments"), -1);
	new_argv = refactor_args(argc, argv);
	if (new_argv == NULL)
		return (-1);
	i = 0;
	while (new_argv[i] != NULL)
	{
		if (!valid_arg(new_argv[i]) || i > 4)
			return (ft_perror(1, "Something wrong with the Args"), -1);
		value = (int32_t)ft_custom_atoll(new_argv[i++]);
		if (value <= 0)
			return (ft_perror(1, "Argument out of range"), -1);
		err = init_vars(table, value, i);
		if (err != 0)
			return (-1);
	}
	free_2d_arr(new_argv);
	return (0);
}

/* -------------------------------------------------------------------------- */
