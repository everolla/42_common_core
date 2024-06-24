/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:29:24 by everolla          #+#    #+#             */
/*   Updated: 2023/06/20 10:33:29 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	send_string(pid_t pid, const char *string)
{
	int	bit;
	int	v;

	while (*string)
	{
		v = *string;
		bit = 0;
		while (bit < 8)
		{
			if ((v & (1 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(1000);
		}
		string++;
	}
}

void	recv(int sign)
{
	(void)sign;
	write(1, "The message has been delivered correctly.\n", 42);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		return (ft_printf("Wrong input!"));
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &recv);
	send_string(server_pid, argv[2]);
	send_string(server_pid, "\n");
	return (0);
}
