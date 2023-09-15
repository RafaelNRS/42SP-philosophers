/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:45 by ranascim          #+#    #+#             */
/*   Updated: 2023/09/15 11:50:17 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/types.h>


struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t       t1;
	int             id;
	int             eat_cont;
	int             status;
	int             eating;
	uint64_t        time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_data
{
	pthread_t       *tid;
	int             philo_num;
	int             meals_nb;
	int             dead;
	int             finished;
	t_philo         *philos;
	uint64_t        death_time;
	uint64_t        eat_time;
	uint64_t        sleep_time;
	uint64_t        start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_data;

void	ft_bzero(void *s, int n);

int	ft_is_space(char c);

int	ft_isdigit(int c);

int	ft_digit_count(long n);

int	ft_atoi(const char *nptr);

void	*ft_calloc(int nmemb, int size);

char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif