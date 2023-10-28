/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:58 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/27 22:04:57 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	routine(t_data	*run_data)
{
	pthread_t	*philo_threads;
	t_philo		**philos;

	philo_threads = (pthread_t *) malloc(sizeof(pthread_t) * \
		run_data->num_of_philos);
	philos = (t_philo **) malloc(sizeof(t_philo *) * run_data->num_of_philos);
	exec_threads(run_data, philo_threads, philos);
	free(philo_threads);
	free_philos(philos, run_data->num_of_philos);
	free_data(run_data);
}

void	init_forks(t_data *run_data)
{
	int	i;

	i = 0;
	run_data->fork = malloc(sizeof(pthread_mutex_t *) \
		* run_data->num_of_philos);
	while (run_data->num_of_philos > i)
	{
		run_data->fork[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(run_data->fork[i], NULL);
		i++;
	}
	run_data->get_time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(run_data->get_time, NULL);
	run_data->print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(run_data->print, NULL);
	run_data->dead_or_alive_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(run_data->dead_or_alive_mutex, NULL);
	run_data->last_meal_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(run_data->last_meal_mutex, NULL);
}

t_data	*init_data(char **argv)
{
	t_data	*run_data;

	run_data = malloc(sizeof(t_data));
	run_data->num_of_philos = ft_atoi(argv[1]);
	run_data->time_to_die = ft_atoi(argv[2]);
	run_data->time_to_eat = ft_atoi(argv[3]);
	run_data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		run_data->opt_num_of_meals = ft_atoi(argv[5]);
	else
		run_data->opt_num_of_meals = -1;
	run_data->timestamp_init = -1;
	run_data->someone_died = 0;
	init_forks(run_data);
	return (run_data);
}

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (1);
	if (! validate(argv))
	{
		printf("Usage: philosophers <philos> <time_to_die> <time_to_eat>");
		printf(" <time_to_sleep> <nbr_of_times_must_eat> (opt)\n");
		return (1);
	}
	routine(init_data(argv));
	return (1);
}
