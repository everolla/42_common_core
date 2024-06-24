/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav & everolla <lfrancav@student.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:11:30 by lfrancav &        #+#    #+#             */
/*   Updated: 2024/02/20 20:11:31 by lfrancav &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit(t_arg *arg)
{
	write(1, "beeeeexit\n", 10);
	if (arg && arg->value)
		exit(ft_atoi(arg->value));
	else
		exit(0);
}
