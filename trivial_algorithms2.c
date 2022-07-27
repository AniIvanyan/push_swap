/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:57:36 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/27 11:53:22 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *this)
{
	int	i;
	int	index;
	int	min;
	t_node *temp;

	i = 0;
	index = 0;
	temp = this->head;
	if (!this)
		return (-1);
	min = temp->data;
	while (i < this->size)
	{
		if (temp->data < min)
		{
			min = temp->data;
			index++;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	min_to_top(t_stack *this, int index)
{
	if (index == 1)
	{
		ft_sa(this);
		ft_putstr("sa\n");
	}
	else if (index == 2)
	{
		ft_ra(this);
		ft_ra(this);
		ft_putstr("ra\nra\n");
	}
	else if (index == 3)
	{
		ft_rra(this);
		ft_rra(this);
		ft_putstr("rra\nrra\n");
	}
	else if (index == 4)
	{
		ft_rra(this);
		ft_putstr("rra\n");
	}
}
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted(stack_a))
		return ;
	min_to_top(stack_a, find_min(stack_a));
	ft_pb(stack_a, stack_b);
	ft_putstr("pb\n");
	sort_four1(stack_a, stack_b);
	sort_four2(stack_a);
	ft_pa(stack_a, stack_b);
	ft_putstr("pa\n");
}

void	less_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
	{
		sort_three1(stack_a);
		sort_three2(stack_a);
	}
	else if (stack_a->size == 4)
	{
		sort_four1(stack_a, stack_b);
		sort_four2(stack_a);
	}
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}