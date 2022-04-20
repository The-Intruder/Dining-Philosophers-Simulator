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

/* -------------------------------------------------------------------------- */

char	**join_split_args(int argc, char **argv)
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

// int	valid_arg(char *arg)
// {
// 	size_t	i;
// 	size_t	len;

// 	i = 0;
// 	len = ft_strlen(arg);
// 	while (i < len)
// 	{

// 	}
// }

/* -------------------------------------------------------------------------- */

t_table	*read_args(int argc, char **argv)
{
	char	**n_argv;
	size_t	i;

	if (argc <= 1)
		return (ft_perror(1, "read_args", "Not enough arguments"), NULL);
	n_argv = join_split_args(argc, argv);
	i = 0;
	while (n_argv[i])
		printf("%s ", n_argv[i++]);
	return (NULL);
}

/* -------------------------------------------------------------------------- */
