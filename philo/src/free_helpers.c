/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:14:40 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 13:47:13 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	free_philos(t_philo **philos, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}

void	free_data(t_data *run_data)
{
	int	i;

	i = 0;
	while (i < run_data->num_of_philos)
	{
		free(run_data->fork[i]);
		i++;
	}
	free(run_data->fork);
	free(run_data->print);
	free(run_data->get_time);
	free(run_data->dead_or_alive_mutex);
	free(run_data->last_meal_mutex);
	free(run_data);
}
