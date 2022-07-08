/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:29:53 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/08 20:00:32 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

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

enum	e_ops{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
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
void	ft_sa(t_stack *a, t_stack *b);
void	ft_sb(t_stack *a, t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

//stack_ops2
void	ft_ra(t_stack *a, t_stack *b);
void	ft_rb(t_stack *a, t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);

//stack_ops3
void	ft_rra(t_stack *a, t_stack *b);
void	ft_rrb(t_stack *a, t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
#endif