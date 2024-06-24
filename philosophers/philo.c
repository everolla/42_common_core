/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:45:36 by everolla          #+#    #+#             */
/*   Updated: 2023/10/17 16:58:03 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_input(void)
{
	write(1, "invalid input, please try again...\n", 35);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	pthread_t	*threads;

	check_input(argc, argv);
	philo = ft_init(philo, argc, argv);
	init_philo(philo);
	threads = ft_start(philo, threads);
	check_work(philo);
}
