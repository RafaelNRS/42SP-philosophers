/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:58 by ranascim          #+#    #+#             */
/*   Updated: 2023/09/17 15:36:40 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	validate(char **argv)
{
	int		i;
	char		*c;

	i = 1;
	while (argv[i])
	{
		c = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(c, argv[i], ft_strlen(argv[i])) == 0)
			i++;
		else
		{
			free(c);
			return (0);
		}
		free(c);
	}
	return (1);
}

void	*routine(void *arg)
{
	//todo
}

void *check_philos(void *arg)
{
	//todo
}

void	init_threads(t_data *data, int nb)
{
	int		i;
	pthread_t	verify;

	i = 0;
	data->start_time = get_time();
	while (i < nb)
	{
		data->philo[i].last_meal = data->start_time;
		pthread_create(&data->philo[i].thread, NULL, &routine,
			&data->philo[i]);
		i++;
	}
	pthread_create(&verify, NULL, &check_philos, data);
	i = 0;
	while (i < nb)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(verify, NULL);
}

void init_philosophers(t_data *data, int philo_number, int philo_count)
{
	t_philo	*philo;
	
	philo = malloc(philo_number * sizeof(t_philo));
	while (philo_count < philo_number)
	{
		pthread_mutex_init(&philo[philo_count].mutex_last_meal, NULL);
		pthread_mutex_init(&philo[philo_count].mutex_ate_meals, NULL);
		philo[philo_count].philo_id = philo_count + 1;
		philo[philo_count].right_fork = &data->forks[philo_count];
		philo[philo_count].left_fork = &data->forks[(philo_count + 1) % philo_number];
		philo[philo_count].data = data;
		philo[philo_count].nb_ate_meals = 0;
		philo_count++;
	}
	data->philo = philo;
}

void	init_mutex(t_data *data, int fork_count)
{
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->mutex_died, NULL);
	pthread_mutex_init(&data->mutex_finish, NULL);
	data->forks = malloc(data->nb_philos * sizeof(pthread_mutex_t));
	while (fork_count < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[fork_count], NULL);
		fork_count++;
	}
}

void	init_arguments(int argc, char **argv, t_data *data)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->finish = 0;
	data->died = 0;
	if (argv == 6)
		data->nb_times_must_eat = ft_atoi(argv[5]);
	else
		data->nb_times_must_eat = INT64_MAX;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	
	if (argc < 5 || argc > 6)
		return (1);
	if (! validate(argv))
		return (1);
	printf("ok\n");
	init_arguments(argc, argv, &data);
	init_mutex(&data, 0);
	init_philos(&data, data.nb_philos, 0);
}
