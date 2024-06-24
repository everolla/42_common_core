/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:18:24 by everolla          #+#    #+#             */
/*   Updated: 2023/10/16 15:11:53 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void		list_args(char **argv, t_stack **stack_a);
void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
void		ft_error(void);
void		ft_free(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		sa(t_stack **a);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **a);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr_2(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		rrb(t_stack **b);
void		sb(t_stack **b);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_find_index(t_stack *a, int nbr);
int			ft_find_place_b(t_stack *stack_b, int nbr_push);
int			ft_find_place_a(t_stack *a, int nbr);
void		ft_sort(t_stack **stack_a);
int			checksorted(t_stack *stack_a);
void		ft_sort_three(t_stack **stack_a);
t_stack		*ft_parse(int argc, char **argv);
t_stack		*ft_parse_args(char **argv);
void		ft_freestr(char **lst);
int			ft_check_rarb(t_stack *a, t_stack *b, int c, char z);
int			ft_check_rrarrb(t_stack *a, t_stack *b, int c, char z);
int			ft_check_rrarb(t_stack *a, t_stack *b, int c, char z);
int			ft_check_rarrb(t_stack *a, t_stack *b, int c, char z);
int			ft_rotate(t_stack *a, t_stack *b, char c);
int			ft_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_rarrb(t_stack **a, t_stack **b, int c, char s);
t_stack		*ft_process(int argc, char **argv);
int			ft_atoi(const char *str);
void		ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sub_process(char **argv);
void		ft_error(void);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);

#endif
