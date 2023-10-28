/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:25:11 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 13:50:42 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	philo_actions(t_philo *philo)
{
	prints(philo, FORK);
	prints(philo, FORK);
	prints(philo, EAT);
	pthread_mutex_lock(philo->data->dead_or_alive_mutex);
	philo->last_meal = get_current_timestamp(philo);
	philo->meals_had++;
	pthread_mutex_unlock(philo->data->dead_or_alive_mutex);
	usleep((philo)->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	while_alive(t_philo *philo)
{
	while (verify_end(philo) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		if (verify_end(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		philo_actions(philo);
		if (verify_end(philo))
			break ;
		prints(philo, SLEEP);
		usleep((philo)->data->time_to_sleep * 1000);
		if (verify_end(philo))
			break ;
		prints(philo, THINK);
		usleep(1000);
	}
}

void	*philo_routine(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *) philo_data;
	set_timestamps(philo);
	if (single_philo(philo) == 1)
		return (NULL);
	if (philo->id % 2 == 1)
		usleep(1400);
	while_alive(philo);
	return (NULL);
}

int	create_philos_threads(t_data *run_data, pthread_t *philo_threads, \
	t_philo **philos)
{
	int	i;

	i = 0;
	while (i < run_data->num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		initialize_philo(philos[i], run_data, i);
		if (pthread_create(&philo_threads[i], NULL, &philo_routine, \
			(void *) philos[i]))
		{
			printf("Error creating thread!\n");
			free(philo_threads);
			free_philos(philos, run_data->num_of_philos);
			return (0);
		}
		i++;
	}
	return (1);
}

void	exec_threads(t_data *run_data, pthread_t *philo_threads, \
	t_philo **philos)
{
	pthread_t	monitor;
	int			i;

	if (create_philos_threads(run_data, philo_threads, philos) == 0)
		return ;
	pthread_create(&monitor, NULL, &monitor_thread, (void *) philos);
	i = 0;
	while (i < run_data->num_of_philos)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}
