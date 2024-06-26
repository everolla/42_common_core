/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav & everolla <lfrancav@student.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:11:09 by lfrancav &        #+#    #+#             */
/*   Updated: 2024/02/20 20:11:12 by lfrancav &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	ft_echo(t_expression *cmd)
{
	t_arg	*buff;
	int		n;
	int		fd;

	n = 0;
	buff = cmd->args;
	fd = 1;
	if (!buff)
		ft_putstr_fd("\n", fd);
	while (ft_strlen(buff->value) == 2 && ft_strcmp("-n", buff->value))
	{
		buff = buff->next;
		n = 1;
	}
	while (buff)
	{
		ft_putstr_fd(buff->value, fd);
		if (buff->next)
			write(fd, " ", 1);
		buff = buff->next;
	}
	if (n != 1)
		ft_putstr_fd("\n", fd);
	return (0);
}
