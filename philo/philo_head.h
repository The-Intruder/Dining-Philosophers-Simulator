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
#	include <stdio.h>
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
# define EAT	0b0001
# define SLP	0b0010
# define THK	0b0100
# define DDD	0b1000

/* ---------------------------------- TypeDefs ------------------------------ */
typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

typedef struct s_philo {
	struct s_philo	*prev;
	size_t			indx;
	pthread_t		phil;
	pthread_mutex_t	fork;
	int8_t			stat;
	struct s_philo	*next;
}	t_philo;

typedef struct s_table {
	t_uint	time_to_eat;
	t_uint	time_to_thk;
	t_uint	time_to_slp;
	t_uint	time_to_die;
	t_philo	*head;
	t_philo	*tail;
	size_t	size;
}	t_table;

/* --------------------------------- Prototypes ----------------------------- */
// ft_utils //
size_t	ft_strlen(const char *s);
void	ft_free(void **ptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2, char sep);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strcpy(char *dest, const char *src);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// args_pars //
char	**join_split_args(int argc, char **argv);
t_table	*read_args(int argc, char **argv);

// err_utils //
void	ft_perror(int type, char *location, char *cause);

#endif
