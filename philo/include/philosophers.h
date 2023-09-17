/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:45 by ranascim          #+#    #+#             */
/*   Updated: 2023/09/16 13:47:35 by ranascim         ###   ########.fr       */
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


typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_times_must_eat;
	long int			start_time;
	long int			finish;
	long int			died;
	pthread_mutex_t	write;
	pthread_mutex_t	mutex_finish;
	pthread_mutex_t	mutex_died;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

struct s_philo
{
	int				philo_id;
	long int			nb_ate_meals;
	long int			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_ate_meals;
	pthread_t			thread;
	t_data			*data;
};


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