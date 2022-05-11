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
# include <sys/sem.h>
# include <sys/time.h>
# include <sys/types.h> 
# include <sys/wait.h>
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

/* ----------------------------------- Enums -------------------------------- */
enum philo_stat	{EAT = 1, SLP};
enum args_flag	{PLS = 1, DGT};
enum data_stat	{OFF, ON};
enum time_type	{MSEC = 1, USEC};

/* ---------------------------------- TypeDefs ------------------------------ */
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned char		t_uchar;
typedef struct timeval		t_timeval;

typedef struct s_philo {
	pthread_t		monitor_thrd;
	long			last_meal_time;
	int				eat_count;
}	t_philo;

typedef struct s_data {
	semun_t	*forks;
	pid_t	*philos;
	long	start_time;
	long	time_to_eat;
	long	time_to_slp;
	long	time_to_die;
	int		philo_count;
	int		count_to_eat;
}	t_data;

/* --------------------------------- Prototypes ----------------------------- */
// ft_utils
size_t	ft_strlen(const char *s);
void	free_2d_arr(char **ptr_arr);
void	ft_bzero(void *s, size_t n);
void	ft_free(void **ptr);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2, char sep);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

// args_pars
int		init_args(t_data *data, int argc, char **argv);

// data_utils
int		init_data(t_data *data, int philo_count);

// philo_utilities
long	ft_get_usec_timestamp(void);
void	ft_perror(int type, char *cause);
void	ft_usleep(long usec_to_sleep);

// philo_actvts
void	print_safely(t_philo *philo, char *action);

#endif
