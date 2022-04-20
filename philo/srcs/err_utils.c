/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
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

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

void	ft_perror(int type, char *location, char *cause)
{
	if (type == 1)
		write(2, RED"\nError"NNN, 15);
	else if (type == 2)
		write(2, YEL"Warning"NNN, 14);
	write(2, "\tLocation:  ", 12);
	write(2, location, ft_strlen(location));
	write(2, "\n     \tCause:     ", 18);
	write(2, cause, ft_strlen(cause));
	write(2, "\n\n", 2);
}

/* -------------------------------------------------------------------------- */