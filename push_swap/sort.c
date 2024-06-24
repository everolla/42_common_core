/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:38:42 by everolla          #+#    #+#             */
/*   Updated: 2023/10/16 15:16:01 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a);
		if (!checksorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate(*stack_a, *stack_b, 'a');
		while (i >= 0)
		{
			if (i == ft_check_rarb(*stack_a, *stack_b, tmp->nbr, 'a'))
				i = ft_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_check_rrarrb(*stack_a, *stack_b, tmp->nbr, 'a'))
				i = ft_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_check_rarrb(*stack_a, *stack_b, tmp->nbr, 'a'))
				i = ft_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_check_rrarb(*stack_a, *stack_b, tmp->nbr, 'a'))
				i = ft_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate(*stack_a, *stack_b, 'b');
		while (i >= 0)
		{
			if (i == ft_check_rarb(*stack_a, *stack_b, tmp->nbr, 'b'))
				i = ft_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_check_rarrb(*stack_a, *stack_b, tmp->nbr, 'b'))
				i = ft_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_check_rrarrb(*stack_a, *stack_b, tmp->nbr, 'b'))
				i = ft_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_check_rrarb(*stack_a, *stack_b, tmp->nbr, 'b'))
				i = ft_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !checksorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!checksorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				rra(stack_a);
		}
	}
}
