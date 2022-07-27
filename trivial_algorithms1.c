/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:47:24 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/27 12:53:30 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->data > stack_a->head->next->data)
		ft_ops(stack_a, stack_b, sa);
}

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	else if (stack_a->head->data < stack_a->head->next->data
		&& stack_a->head->data < stack_a->head->prev->data)
	{
		ft_ops(stack_a, stack_b, sa);
		ft_ops(stack_a, stack_b, ra);
	}
	else if (stack_a->head->data < stack_a->head->next->data)
		ft_ops(stack_a, stack_b, rra);
	else if (stack_a->head->data < stack_a->head->prev->data)
		ft_ops(stack_a, stack_b, sa);
	else if (stack_a->head->next->data < stack_a->head->prev->data)
		ft_ops(stack_a, stack_b, ra);
	else
	{
		ft_ops(stack_a, stack_b, sa);
		ft_ops(stack_a, stack_b, rra);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	ft_ops(stack_a, stack_b, pb);
	sort_three(stack_a, stack_b);
	ft_ops(stack_a, stack_b, pa);
	if (stack_a->head->data < stack_a->head->next->data)
		return ;
	else if (stack_a->head->data > stack_a->head->prev->data)
		ft_ops(stack_a, stack_b, ra);
	else if (stack_a->head->data < stack_a->head->next->next->data)
		ft_ops(stack_a, stack_b, sa);
	else
	{
		ft_ops(stack_a, stack_b, rra);
		ft_ops(stack_a, stack_b, sa);
		ft_ops(stack_a, stack_b, ra);
		ft_ops(stack_a, stack_b, ra);
	}
}

