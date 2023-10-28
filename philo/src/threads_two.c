/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:48:20 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 13:50:10 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	initialize_philo(t_philo *philo, t_data *run_data, int i)
{
	philo->data = run_data;
	philo->id = i;
	philo->meals_had = 0;
	philo->left_fork = run_data->fork[i];
	philo->right_fork = run_data->fork[(i + 1) % run_data->num_of_philos];
	if ((i + 1) % run_data->num_of_philos == 0)
	{
		philo->right_fork = run_data->fork[i];
		philo->left_fork = run_data->fork[(i + 1) % run_data->num_of_philos];
	}
	philo->last_meal = -1;
}

int	verify_end(t_philo *philo)
{
	pthread_mutex_lock(philo->data->dead_or_alive_mutex);
	if (philo->data->someone_died == 1 || philo->meals_had == \
		philo->data->opt_num_of_meals)
	{
		pthread_mutex_unlock(philo->data->dead_or_alive_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->data->dead_or_alive_mutex);
	return (0);
}

int	single_philo(t_philo *philo)
{
	if (philo->data->num_of_philos == 1)
	{
		prints(philo, FORK);
		usleep(philo->data->time_to_die * 1000);
		prints(philo, DIE);
		return (1);
	}
	return (0);
}
