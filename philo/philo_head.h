/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_head.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:57:29 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:13 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HEAD_H
# define PHILO_HEAD_H

/* ---------------------------------- Libraries ----------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>

/* ----------------------------------- Macros ------------------------------- */
// Color Codes //
# define NNN	"\033[0m"
# define RED	"\033[31m"
# define GRN	"\033[32m"
# define YEL	"\033[33m"
# define BLU	"\033[34m"
# define MGN	"\033[35m"
# define CYN	"\033[36m"
# define GRA	"\033[37m"

// Other things //
# define EAT	0b001
# define SLP	0b010
# define THK	0b100

/* ---------------------------------- TypeDefs ------------------------------ */
typedef struct s_philo {
	struct s_philo	*prev;
	size_t			indx;
	pthread_t		phil;
	pthread_mutex_t	fork;
	int8_t			actn;
	struct s_philo	*next;
}	t_philo;

typedef struct s_table {
	t_philo	*head;
	t_philo	*tail;
	size_t	size;
}	t_table;

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

/* --------------------------------- Prototypes ----------------------------- */

#endif
