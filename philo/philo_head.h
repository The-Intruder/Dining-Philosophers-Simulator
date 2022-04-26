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
// Functions & Functionalities //
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
// Macros & Typedefs //
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

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
# define EAT	0b0001
# define SLP	0b0010
# define THK	0b0100
# define DDD	0b1000

// Other things //
# define PLS	0b0001
# define DGT	0b0010

/* ---------------------------------- TypeDefs ------------------------------ */
typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

//typedef struct s_table	t_table;

typedef struct s_philo {
	void			*table;
	pthread_t		ph_thrd;
	pthread_mutex_t	fork_a;
	int8_t			state;
	size_t			id;
}	t_philo;

typedef struct s_table {
	t_philo		*philos;
	size_t		philo_count;
	useconds_t	time_to_eat;
	useconds_t	time_to_slp;
	useconds_t	time_to_die;
	int64_t		count_to_eat;
}	t_table;

/* --------------------------------- Prototypes ----------------------------- */
// ft_utils //
int64_t	ft_custom_atoll(const char *str);
size_t	ft_strlen(const char *s);
void	ft_free(void **ptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	free_2d_arr(char **ptr_arr);
char	*ft_strjoin(char const *s1, char const *s2, char sep);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strcpy(char *dest, const char *src);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// args_pars //
int		init_args(t_table *table, int argc, char **argv);

// table_utils //
int		init_table(t_table *table, size_t philo_count);

// err_utils //
void	ft_perror(int type, char *cause);

// philo_actvts //
int		philo_sleep(t_philo *philo, useconds_t time_to_sleep);
int		philo_think(t_philo *philo, useconds_t time_to_think);
int		philo_eat(t_philo *philo, useconds_t time_to_eat);
int		philo_take_fork(pthread_mutex_t *fork);
int		philo_put_fork(pthread_mutex_t *fork);

#endif
