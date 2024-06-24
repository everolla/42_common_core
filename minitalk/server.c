/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:29:34 by everolla          #+#    #+#             */
/*   Updated: 2023/06/20 10:34:40 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	signal_handler(int sign, siginfo_t *info, void *context)
{
	static int	bit_counter;
	static int	value;

	(void)context;
	if (sign == SIGUSR1)
		value += 1 << bit_counter;
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &value, 1);
		if (value == '\n')
			kill(info->si_pid, SIGUSR1);
		bit_counter = 0;
		value = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &act, (void *)0);
	sigaction(SIGUSR2, &act, (void *)0);
	sigemptyset(&act.sa_mask);
	ft_printf("Starting server...\n");
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
