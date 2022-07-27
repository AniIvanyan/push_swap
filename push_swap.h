/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:29:53 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/28 01:05:00 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}				t_stack;

enum ops{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

// stack_utils1
t_stack	*ft_stk_construct(void);
void	ft_stk_push_int(t_stack *this, int data);
void	ft_stk_push_node(t_stack *this, t_node *node);
t_node	*ft_stk_pop(t_stack *this);
t_node	*ft_stk_top(t_stack *this);

//stack_utils2
void	ft_stk_rotate(t_stack *this);
void	ft_stk_revrotate(t_stack *this);

//stack_ops1
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

//stack_ops2
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);

//stack_ops3
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_ops(t_stack *a, t_stack *b, enum ops ops);
void	ft_ops_helper1(t_stack *a, t_stack *b, enum ops ops);
void	ft_ops_helper2(t_stack *a, t_stack *b, enum ops ops);

//helper
int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_putstr(const char *s);
int		ft_sorted(t_stack *this);

//trivial_algorithms1
void	sort_two(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
int		find_min(t_stack *this);
void	min_to_top(t_stack *this, int index5, int index4);

//trivial_algorithms2
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	less_five(t_stack *stack_a, t_stack *stack_b);

//big_algorithms
int	find_max(t_stack *this);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
#endif