/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:48:39 by everolla          #+#    #+#             */
/*   Updated: 2023/10/17 16:58:30 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define THINKING "is thinking"
# define FORK "has taken a fork"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DEAD "is dead"

typedef struct s_general
{
	int				philos;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				meals_counter;
	unsigned long	start_time;
	pthread_mutex_t	print;
}					t_general;

typedef struct s_philo
{
	t_general		*general;
	int				index_philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long	last_meal;
}					t_philo;

int					ft_atoi(const char *str);
void				check_input(int argc, char **argv);
unsigned long		now_ts(void);
t_philo				*ft_init(t_philo *philo, int argc, char **argv);
void				init_philo(t_philo *philo);
void				message(t_philo *philo, char *action);
void				ft_exit(t_philo *philo, int i);
void				check_work(t_philo *philo);
void				eat(t_philo *philo);
void				*work(void *arguments);
pthread_t			*ft_start(t_philo *philo, pthread_t *threads);
void				ft_error_input(void);

#endif