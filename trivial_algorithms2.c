/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:57:36 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/28 01:39:21 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	min_to_top(stack_a, 0, find_min(stack_a));
	ft_ops(stack_a, stack_b, pb);
	sort_three(stack_a, stack_b);
	ft_ops(stack_a, stack_b, pa);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	min_to_top(stack_a, find_min(stack_a), 0);
	ft_ops(stack_a, stack_b, pb);
	sort_four(stack_a, stack_b);
	ft_ops(stack_a, stack_b, pa);
}

void	less_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_two(stack_a, stack_b);
	else if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}