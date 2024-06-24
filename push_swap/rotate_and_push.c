/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:04:37 by everolla          #+#    #+#             */
/*   Updated: 2023/10/16 15:15:47 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			rr(a, b);
		while ((*a)->nbr != c)
			ra(a);
		while (ft_find_place_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			rr(a, b);
		while ((*b)->nbr != c)
			rb(b);
		while (ft_find_place_a(*a, c) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	ft_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			rrr(a, b);
		while ((*a)->nbr != c)
			rra(a);
		while (ft_find_place_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			rrr(a, b);
		while ((*b)->nbr != c)
			rrb(b);
		while (ft_find_place_a(*a, c) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

int	ft_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			rra(a);
		while (ft_find_place_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			rra(a);
		while ((*b)->nbr != c)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

int	ft_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a);
		while (ft_find_place_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ra(a);
		while ((*b)->nbr != c)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}

int	ft_rotate(t_stack *a, t_stack *b, char c)
{
	int		i;
	t_stack	*tmp;

	if (c == 'b')
		tmp = b;
	else
		tmp = a;
	i = ft_check_rrarrb(a, b, tmp->nbr, c);
	while (tmp)
	{
		if (i > ft_check_rarb(a, b, tmp->nbr, c))
			i = ft_check_rarb(a, b, tmp->nbr, c);
		if (i > ft_check_rrarrb(a, b, tmp->nbr, c))
			i = ft_check_rrarrb(a, b, tmp->nbr, c);
		if (i > ft_check_rarrb(a, b, tmp->nbr, c))
			i = ft_check_rarrb(a, b, tmp->nbr, c);
		if (i > ft_check_rrarb(a, b, tmp->nbr, c))
			i = ft_check_rrarb(a, b, tmp->nbr, c);
		tmp = tmp->next;
	}
	return (i);
}
