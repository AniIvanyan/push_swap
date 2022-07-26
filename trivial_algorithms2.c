/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:57:36 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/26 14:48:26 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five1(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_putstr("pb\n");
	sort_four1(stack_a, stack_b);
	sort_four2(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_putstr("pa\n");
	if (stack_a->head->data < stack_a->head->next->data)
		return;
	else if (stack_a->head->data < stack_a->head->next->next->data)
	{
		ft_sa(stack_a, stack_a);
		ft_putstr("sa\n");
	}
	else if (stack_a->head->data > stack_a->head->prev->data)
	{
		ft_ra(stack_a, stack_a);
		ft_putstr("ra\n");
	}
}

void	sort_five2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->data < stack_a->head->next->data)
		return;
		
	else if (stack_a->head->data > stack_a->head->prev->prev->data)
	{
		ft_rra(stack_a, stack_b);
		ft_sa(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
		ft_putstr("rra\nsa\nra\nra\n");
	}
	else
	{
		ft_rra(stack_a, stack_b);
		ft_sa(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
		ft_sa(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
		ft_putstr("rra\nsa\nrra\nsa\nrra\nrra\n");
	}
}

void	less_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_two(stack_a, stack_b);
	else if (stack_a->size == 3)
	{
		sort_three1(stack_a, stack_b);
		sort_three2(stack_a, stack_b);
	}
	else if (stack_a->size == 4)
	{
		sort_four1(stack_a, stack_b);
		sort_four2(stack_a, stack_b);
	}
	else if (stack_a->size == 5)
	{
		sort_five1(stack_a, stack_b);
		sort_five2(stack_a, stack_b);
	}
}