/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/05/07 18:10:25 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_head.h"

/* -------------------------------------------------------------------------- */

static int	is_valid_arg(char *arg)
{
	int	flag;
	int	i;

	if (arg == NULL || *arg == '\0')
		return (ft_perror(1, "Invalid Argument"), 0);
	i = -1;
	flag = 0;
	while (arg[++i])
	{
		if ((flag & SPC) == 0 && ft_isspace(arg[i]))
			flag = 0;
		else if (flag == 0 && arg[i] == '+')
			flag |= SPC;
		if (!ft_isdigit(arg[i]))
			return (ft_perror(1, "Invalid Argument"), 0);
		else
			flag |= DGT;
	}
	return (1);
}

/* -------------------------------------------------------------------------- */

static void	init_vars(t_data *data, int value, int var_numb)
{
	data->count_to_eat = -1;
	if (var_numb == 1)
		data->philo_count = value;
	else if (var_numb == 2)
		data->time_to_die = (long)value * 1000;
	else if (var_numb == 3)
		data->time_to_eat = (long)value * 1000;
	else if (var_numb == 4)
		data->time_to_slp = (long)value * 1000;
	else if (var_numb == 5)
		data->count_to_eat = value;
}

/* -------------------------------------------------------------------------- */

int	init_args(t_data *data, int argc, char **argv)
{
	int		value;
	int		i;

	if (argc != 5 && argc != 6)
		return (ft_perror(1, "Less/More arguments than expected"), -1);
	i = 0;
	while (++i < argc)
	{
		if (!is_valid_arg(argv[i]))
			return (-1);
		value = ft_atoi(argv[i]);
		if (((i == 1 || i == 5) && value <= 0) || value < 0)
			return (ft_perror(1, "Invalid argument value"), -1);
		init_vars(data, value, i);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
