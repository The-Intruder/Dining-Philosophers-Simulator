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

static size_t	args_count_is_valid(char **new_argv)
{
	size_t	i;

	i = 0;
	while (new_argv[i])
		i++;
	if (i != 4 && i != 5)
		return (ft_perror(1, "Less/More arguments than expected"), \
			free_2d_arr(new_argv), 0);
	return (1);
}

/* -------------------------------------------------------------------------- */

static int	is_valid_arg(char *arg)
{
	int8_t	flag;
	int		i;

	if (arg == NULL || *arg == '\0')
		return (ft_perror(1, "Invalid Argument"), 0);
	i = -1;
	flag = 0;
	while (arg[++i])
	{
		if ((flag & PLS) == 0 && ft_isspace(arg[i]))
			flag = 0;
		else if (flag == 0 && arg[i] == '+')
			flag |= PLS;
		else if (!ft_isdigit(arg[i]))
			return (ft_perror(1, "Invalid Argument"), 0);
		else
			flag |= DGT;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */

static char	**refactor_args(int argc, char **argv)
{
	int		i;
	void	*ptr;
	char	*jnd_args;
	char	**spltd_args;

	i = 1;
	jnd_args = ft_strdup(argv[i]);
	if (!is_valid_arg(argv[i]) || jnd_args == NULL || *jnd_args == '\0')
		return (free(jnd_args), NULL);
	while (++i < argc)
	{
		if (!is_valid_arg(argv[i]))
			return (free(jnd_args), NULL);
		ptr = jnd_args;
		jnd_args = ft_strjoin(jnd_args, argv[i], ' ');
		ft_free((void **)&ptr);
		if (jnd_args == NULL || *jnd_args == '\0')
			return (free(jnd_args), NULL);
	}
	spltd_args = ft_split(jnd_args, ' ');
	ft_free((void **)&jnd_args);
	if (spltd_args == NULL || *spltd_args == NULL)
		ft_free((void **)spltd_args);	// ????????????????????????????????????
	return (spltd_args);
}

/* -------------------------------------------------------------------------- */

static int	init_vars(t_table *table, int value, int var_numb)
{
	table->count_to_eat = -1;
	if (var_numb == 1)
		table->time_to_die = (useconds_t)value * 1000;
	else if (var_numb == 2)
		table->time_to_eat = (useconds_t)value * 1000;
	else if (var_numb == 3)
		table->time_to_slp = (useconds_t)value * 1000;
	else if (var_numb == 4)
		table->count_to_eat = value;
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_args(t_table *table, int argc, char **argv)
{
	char	**new_argv;
	int		value;
	int		i;

	new_argv = refactor_args(argc, argv);
	if (new_argv == NULL || !args_count_is_valid(new_argv))
		return (-1);
	i = 0;
	while (new_argv[++i] != NULL)
	{
		if (!is_valid_arg(new_argv[i]))
			return (-1);
		value = ft_atoi(new_argv[i]);
		if ((i == 4 && value < 0) || (i != 4 && value <= 0))
			return (ft_perror(1, "Invalid argument value"), -1);
		if (init_vars(table, value, i) != 0)
			return (-1);
	}
	value = ft_atoi(new_argv[0]);
	if (value <= 0)
		return (ft_perror(1, "Invalid argument value"), -1);
	if (init_table(table, value) != 0)
		return (-1);
	free_2d_arr(new_argv);
	return (0);
}

/* -------------------------------------------------------------------------- */
