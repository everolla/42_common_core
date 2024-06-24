/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:45 by everolla          #+#    #+#             */
/*   Updated: 2023/10/16 15:16:54 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_rarb(t_stack *a, t_stack *b, int c, char z)
{
	int	i;

	if (z == 'b')
	{
		i = ft_find_place_a(a, c);
		if (i < ft_find_index(b, c))
			i = ft_find_index(b, c);
		return (i);
	}
	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

int	ft_check_rrarrb(t_stack *a, t_stack *b, int c, char z)
{
	int	i;

	i = 0;
	if (z == 'b')
	{
		if (ft_find_place_a(a, c))
			i = ft_lstsize(a) - ft_find_place_a(a, c);
		if ((i < (ft_lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
			i = ft_lstsize(b) - ft_find_index(b, c);
		return (i);
	}
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

int	ft_check_rrarb(t_stack *a, t_stack *b, int c, char z)
{
	int	i;

	i = 0;
	if (z == 'b')
	{
		if (ft_find_place_a(a, c))
			i = ft_lstsize(a) - ft_find_place_a(a, c);
		i = ft_find_index(b, c) + i;
		return (i);
	}
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

int	ft_check_rarrb(t_stack *a, t_stack *b, int c, char z)
{
	int	i;

	i = 0;
	if (z == 'b')
	{
		if (ft_find_index(b, c))
			i = ft_lstsize(b) - ft_find_index(b, c);
		i = ft_find_place_a(a, c) + i;
		return (i);
	}
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}
