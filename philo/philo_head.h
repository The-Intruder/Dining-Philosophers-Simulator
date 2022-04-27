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
# include <sys/time.h>

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

// Philos Activities Flags //
# define EAT	0b0001
# define SLP	0b0010
# define THK	0b0100
# define DDD	0b1000

// Fork Activities //
# define TAK	0b01
# define PUT	0b10

// Other things //
# define PLS	0b01
# define DGT	0b10

/* ---------------------------------- TypeDefs ------------------------------ */
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned char		t_uchar;
typedef struct timeval		t_timeval;

//typedef struct s_table	t_table;

typedef struct s_philo {
	struct s_table	*table;
	pthread_t		ph_thrd;
	pthread_mutex_t	fork;
	int8_t			state;
	size_t			id;
}	t_philo;

typedef struct s_table {
	t_philo			*philos;
	pthread_mutex_t	msg_mtx;
	useconds_t		time_to_eat;
	useconds_t		time_to_slp;
	useconds_t		time_to_die;
	int64_t			count_to_eat;
	size_t			philo_count;
	t_ulong			start_time;
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

// philo_utils //
t_ulong	ft_get_time_in_usec(void);
void	ft_perror(int type, char *cause);
void	ft_usleep(useconds_t usec_to_sleep);

// philo_actvts //
void	print_safely(t_table *table, size_t id, char *state);
void	forks_action(t_philo *philo_a, t_philo *philo_b, int8_t state);
void	philo_sleep(t_philo *philo, useconds_t time_to_sleep);
void	philo_think(t_philo *philo, useconds_t time_to_think);
void	philo_eat(t_philo *philo, useconds_t time_to_eat);

#endif
