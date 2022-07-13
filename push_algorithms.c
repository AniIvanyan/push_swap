/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:47:24 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/13 19:30:52 by aivanyan         ###   ########.fr       */
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

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->data < stack_a->head->next->data
		&& stack_a->head->data < stack_a->head->prev->data
		&& stack_a->head->next->data >stack_a->head->prev->data)
	{
		ft_sa(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
		ft_putstr("sa\nra\n");
	}

	else if (stack_a->head->data > stack_a->head->next->data
			&& stack_a->head->data < stack_a->head->prev->data)
	{
		ft_sa(stack_a, stack_b);
		ft_putstr("sa\n");
	}

	else if (stack_a->head->data < stack_a->head->next->data
			&& stack_a->head->data > stack_a->head->prev->data)
	{
		ft_rra(stack_a, stack_b);
		ft_putstr("rra\n");
	}
	else if (stack_a->head->data > stack_a->head->next->data
			&& stack_a->head->data > stack_a->head->prev->data
			&& stack_a->head->next->data < stack_a->head->prev->data)
	{
		ft_ra(stack_a, stack_b);
		ft_putstr("ra\n");
	}
	else if (stack_a->head->data > stack_a->head->next->data
			&& stack_a->head->data > stack_a->head->prev->data)
	{
		ft_sa(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
		ft_putstr("sa\nrra\n");
	}
}

void	less_three(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_two(stack_a, stack_b);
	else if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
}