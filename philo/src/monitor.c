/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:49:05 by ranascim          #+#    #+#             */
/*   Updated: 2023/09/25 08:24:56 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	while_monitor(t_philo **philos, int *i, int *eats_count)
{
	if (get_current_timestamp(philos[*i]) - philos[*i]->last_meal > \
		philos[*i]->data->time_to_die)
	{
		while (*eats_count < philos[*i]->data->num_of_philos \
			&& philos[*eats_count]->meals_had \
			== philos[*eats_count]->data->opt_num_of_meals)
			(*eats_count)++;
		if (*eats_count == philos[*i]->data->num_of_philos \
			&& philos[*i]->data->opt_num_of_meals != -1)
		{
			pthread_mutex_unlock(philos[*i]->data->dead_or_alive_mutex);
			return (0);
		}
		philos[*i]->data->someone_died = 1;
		prints(philos[*i], DIE);
		pthread_mutex_unlock(philos[*i]->data->dead_or_alive_mutex);
		return (0);
	}
	return (1);
}

void	*monitor_thread(void *philos_data)
{
	t_philo	**philos;
	int		i;
	int		eats_count;

	philos = (t_philo **) philos_data;
	i = 0;
	eats_count = 0;
	if (philos[i]->data->num_of_philos == 1)
		return (NULL);
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(philos[i]->data->dead_or_alive_mutex);
		if (while_monitor(philos, &i, &eats_count) == 0)
			return (NULL);
		pthread_mutex_unlock(philos[i]->data->dead_or_alive_mutex);
		if (i == philos[i]->data->num_of_philos -1)
			i = 0;
		i++;
	}
	return (NULL);
}
