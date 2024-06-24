/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:39:36 by everolla          #+#    #+#             */
/*   Updated: 2023/10/16 15:14:29 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
