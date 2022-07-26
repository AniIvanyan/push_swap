/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:47:24 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/26 14:13:22 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->data > stack_a->head->next->data)
		{
			ft_sa(stack_a, stack_b);
			ft_putstr("sa\n");
		}
}

void	sort_three1(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	
	else if (stack_a->head->data < stack_a->head->next->data
		&& stack_a->head->data < stack_a->head->prev->data)
	{
		ft_sa(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
		ft_putstr("sa\nra\n");
	}
	
	else if (stack_a->head->data < stack_a->head->next->data)
	{
		ft_rra(stack_a, stack_b);
		ft_putstr("rra\n");
	}

	else if (stack_a->head->data < stack_a->head->prev->data)
	{
		ft_sa(stack_a, stack_b);
		ft_putstr("sa\n");
	}
}

void	sort_three2(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	
	else if (stack_a->head->next->data < stack_a->head->prev->data)
	{
		ft_ra(stack_a, stack_b);
		ft_putstr("ra\n");
	}

	else 
	{
		ft_sa(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
		ft_putstr("sa\nrra\n");
	}
}

void	sort_four1(t_stack *stack_a, t_stack *stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_putstr("pb\n");
	sort_three1(stack_a, stack_b);
	sort_three2(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_putstr("pa\n");
	if (stack_a->head->data < stack_a->head->next->data)
		return ;
	else if (stack_a->head->data > stack_a->head->prev->data)
	{
		ft_ra(stack_a, stack_b);
		ft_putstr("ra\n");
	}
}

void	sort_four2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->data < stack_a->head->next->data)
		return ;
		
	else if (stack_a->head->data > stack_a->head->next->data
			&& stack_a->head->data < stack_a->head->next->next->data)
	{
		ft_sa(stack_a, stack_b);
		ft_putstr("sa\n");
	}
	else
	{
		ft_rra(stack_a, stack_b);
		ft_sa(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
		ft_putstr("rra\nsa\nra\nra\n");
	}	
}
