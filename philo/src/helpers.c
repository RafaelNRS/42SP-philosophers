/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:34:37 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 13:57:54 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	set_timestamps(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(philo->data->get_time);
	if (gettimeofday(&current_time, NULL))
	{
		printf("Error geting time of day!\n");
		return ;
	}
	if (philo->data->timestamp_init == -1)
		philo->data->timestamp_init = (current_time.tv_sec * 1000) + \
		(current_time.tv_usec / 1000);
	pthread_mutex_unlock(philo->data->get_time);
}

long long	get_current_timestamp(t_philo *philo)
{
	struct timeval	current_time;
	long long		return_time;	

	if (gettimeofday(&current_time, NULL))
	{
		printf("Error geting time of day!\n");
		return (-1);
	}
	return_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000) \
	- philo->data->timestamp_init;
	return (return_time);
}

void	prints(t_philo *philo, int action)
{
	pthread_mutex_lock(philo->data->print);
	if (action == FORK)
		printf("%lld Philosopher %d has taken a fork.\n", \
		get_current_timestamp(philo), (philo)->id + 1);
	else if (action == EAT)
		printf("%lld Philosopher %d is eating.\n", \
		get_current_timestamp(philo), (philo)->id + 1);
	else if (action == SLEEP)
		printf("%lld Philosopher %d is sleeping.\n", \
		get_current_timestamp(philo), (philo)->id + 1);
	else if (action == THINK)
		printf("%lld Philosopher %d is thinking.\n", \
		get_current_timestamp(philo), (philo)->id + 1);
	else if (action == DIE)
		printf("%lld Philosopher %d died.\n", \
		get_current_timestamp(philo), (philo)->id + 1);
	else
		printf("Invalid action.\n");
	pthread_mutex_unlock(philo->data->print);
}
