/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:46:02 by everolla          #+#    #+#             */
/*   Updated: 2023/10/17 17:00:09 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_philo *philo, int i)
{
	int	k;

	k = 0;
	message(&philo[i], DEAD);
	pthread_mutex_destroy(&philo->general->print);
	free(philo->general);
	while (k < philo->index_philo)
		pthread_mutex_destroy(philo[k++].right_fork);
	free(philo);
	exit(0);
}

void	check_work(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->general->philos)
	{
		if (philo[i].last_meal > 0 && (now_ts()
				- philo[i].last_meal) > philo->general->time_death)
			break ;
		if (philo[i].general->meals_counter == philo->general->max_meals)
			break ;
		i = (i + 1) % philo->general->philos;
	}
	ft_exit(philo, i);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	message(philo, FORK);
	message(philo, FORK);
	message(philo, EATING);
	philo->last_meal = now_ts();
	philo->general->meals_counter++;
	usleep(philo->general->time_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*work(void *arguments)
{
	t_philo	*philo;

	philo = (t_philo *)arguments;
	if (philo->index_philo % 2 != 0)
		usleep(100);
	while (1)
	{
		eat(philo);
		message(philo, SLEEPING);
		usleep(philo->general->time_sleep * 1000);
		message(philo, THINKING);
	}
}

pthread_t	*ft_start(t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	threads = malloc(sizeof(pthread_t) * philo->general->philos);
	while (i < philo->general->philos)
	{
		pthread_create(&threads[i], (void *)0, &work, &philo[i]);
		i++;
	}
}
