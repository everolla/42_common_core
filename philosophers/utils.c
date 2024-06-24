/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:45:47 by everolla          #+#    #+#             */
/*   Updated: 2023/10/17 16:11:34 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_input(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	if (argc > 6 || argc < 5)
		ft_error_input();
	while (argv[i])
	{
		while (argv[i][y])
		{
			if (argv[i][y] >= '0' && argv[i][y] <= '9')
				y++;
			else
				ft_error_input();
		}
		i++;
		y = 0;
	}
}

unsigned long	now_ts(void)
{
	struct timeval	current_time;
	unsigned long	t;

	gettimeofday(&current_time, NULL);
	t = ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
	return (t);
}

t_philo	*ft_init(t_philo *philo, int argc, char **argv)
{
	int				i;
	t_general		*general;
	pthread_mutex_t	mutex;

	i = 0;
	general = malloc(sizeof(t_general));
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	while (i < ft_atoi(argv[1]))
		philo[i++].general = general;
	philo->general->philos = ft_atoi(argv[1]);
	philo->general->time_death = ft_atoi(argv[2]);
	philo->general->time_eat = ft_atoi(argv[3]);
	philo->general->time_sleep = ft_atoi(argv[4]);
	philo->general->max_meals = 0;
	philo->general->meals_counter = 1;
	if (argv[5])
	{
		philo->general->max_meals = ft_atoi(argv[5]) * philo->general->philos;
		philo->general->meals_counter = 0;
	}
	pthread_mutex_init(&mutex, (void *)0);
	philo->general->print = mutex;
	philo->general->start_time = now_ts();
	return (philo);
}

void	init_philo(t_philo *philo)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(philo->general->philos * sizeof(pthread_mutex_t));
	while (i < philo->general->philos)
	{
		philo[i].index_philo = i;
		pthread_mutex_init(&fork[i], (void *)0);
		if (i == 0)
		{
			pthread_mutex_init(&fork[philo->general->philos - 1], (void *)0);
			philo[i].left_fork = &fork[philo->general->philos - 1];
			philo[i].right_fork = &fork[i];
			philo[philo->general->philos
				- 1].left_fork = &fork[philo->general->philos - 1];
			philo[philo->general->philos - 1].right_fork = &fork[i];
			philo[i].last_meal = 0;
			i++;
			continue ;
		}
		philo[i].left_fork = &fork[i - 1];
		philo[i].right_fork = &fork[i];
		philo[i++].last_meal = 0;
	}
}

void	message(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->general->print);
	printf("%ldms %d %s\n", now_ts() - philo->general->start_time,
		philo->index_philo + 1, action);
	pthread_mutex_unlock(&philo->general->print);
}
