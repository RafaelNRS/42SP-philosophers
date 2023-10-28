/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:45 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 13:50:03 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdint.h>
# include <sys/types.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_eat;
	int				time_to_sleep;
	int				opt_num_of_meals;
	int				someone_died;
	long long		timestamp_init;
	long long		time_to_die;
	pthread_mutex_t	**fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*get_time;
	pthread_mutex_t	*dead_or_alive_mutex;
	pthread_mutex_t	*last_meal_mutex;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				meals_had;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int				ft_is_space(char c);

int				ft_isdigit(int c);

int				ft_digit_count(long n);

int				ft_atoi(const char *nptr);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				validate(char **argv);

char			*ft_itoa(int n);

size_t			ft_strlen(const char *s);

void			set_timestamps(t_philo *philo);

void			free_data(t_data *run_data);

void			free_philos(t_philo **philos, int num_of_philos);

void			*monitor_thread(void *philos_data);

void			exec_threads(t_data *run_data, pthread_t *philo_threads, \
		t_philo **philos);

void			prints(t_philo *philo, int action);

void			*ft_calloc(int nmemb, int size);

void			ft_bzero(void *s, int n);

long long		get_current_timestamp(t_philo *philo);

void			initialize_philo(t_philo *philo, t_data *run_data, int i);

int				verify_end(t_philo *philo);

int				single_philo(t_philo *philo);

#endif