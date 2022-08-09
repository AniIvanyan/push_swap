/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:33:50 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/09 19:31:21 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_max(t_stack *this)
{
	int	i;
	int	index;
	int	max;
	t_node *temp;

	if (!this || !this->head)
		return (-1);
	i = 0;
	index = 0;
	temp = this->head;
	max = temp->data;
	while (i < this->size)
	{
		if (temp->data > max)
		{
			max = temp->data;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	index_min;
	int	index_max;
	int	i;
	int	size;

	index_min = find_min(stack_a);
	index_max = find_max(stack_a);
	i = 0;
	size = stack_a->size;
	if (!stack_a || !stack_b || size == 0)
		return ;
	while (i < size)
	{
		if (i == index_min || i == index_max)
			ft_ops(stack_a, stack_b, ra);
		else
			ft_ops(stack_a, stack_b, pb);
		i++;
	}
	if (stack_a->head->data < stack_a->head->next->data)
		ft_ops(stack_a, stack_b, sa);
}

int	find_index(t_stack *this, int data)
{
	int	i;
	t_node *temp;

	if (!this)
		return (-1);
	i = 0;
	temp = this->head;
	while (i < this->size)
	{
		if (temp->data == data)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

int	ops_count_to_top(int size, int index)
{
	if (index <= size / 2)
		return (index);
	return (size - index);
}

int	min_ops_in_a(t_stack *this, int data)
{
	int		i;	
	int		min;
	int		count;
	int		index;
	t_node	*temp;

	if (!this || !this->head)
		return (-1);
	i = 0;
	count = 0;
	index = -1;
	min = this->size;
	temp = this->head;
	while (i < this->size)
	{
		if (data > temp->data && data < temp->next->data)
		{
			count = ops_count_to_top(this->size, (i + 1) % this->size); 
			if (count < min)
			{
				min = count;
				index = (i + 1) % this->size;
			}
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

int	greedy_choice(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	count;
	int	min;
	int	greedy;
	t_node	*temp;
	
	i = 0;
	count = 0;
	min = stack_b->size;
	temp = stack_b->head;
	greedy = temp->data;
	while (i < stack_b->size)
	{
		count = ops_count_to_top(stack_b->size, i) + ops_count_to_top(stack_a->size, min_ops_in_a(stack_a, temp->data));
		if (count < min)
		{
			min = count;
			greedy = temp->data;
		}
		i++;
		temp = temp->next;
	}
	return (greedy);
}

void	top_to_b(t_stack *stack_b, int greedy)
{
	int	index;
	int	i;

	index = find_index(stack_b, greedy);
	i = 0;
	if (index <= stack_b->size / 2)
	{
		while (i < index)
		{
			ft_ops(NULL, stack_b, rb);
			i++;
		}
	}
	else
	{
		i = stack_b->size - index;
		while (i > 0)
		{
			ft_ops(NULL, stack_b, rrb);
			i--;
		}
	}
}

void	insert_in_a(t_stack *stack_a, t_stack *stack_b, int greedy)
{
	int	index;
	int	i;
	
	index = min_ops_in_a(stack_a, greedy);
	i = 0;
	if (index <= stack_a->size / 2)
	{
		while (i < index)
		{
			ft_ops(stack_a, stack_b, ra);
			i++;
		}
	}
	else
	{
		i = stack_a->size - index;
		while (i > 0)
		{
			ft_ops(stack_a, stack_b, rra);
			i--;
		}
	}
	ft_ops(stack_a, stack_b, pa);
}

void	ft_surface(t_stack *stack_a)
{
	int min_index;
	int	i;
	
	min_index = find_min(stack_a);
	i = 0;
	if (min_index <= stack_a->size / 2)
	{
		while (i < min_index)
		{
			ft_ops(stack_a, NULL, ra);
			i++;
		}
	}
	else
	{
		i = stack_a->size - min_index;
		while (i > 0)
		{
			ft_ops(stack_a, NULL, rra);
			i--;
		}
	}
	
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	greedy;
	
	if (!stack_a || !stack_b)
		return ;
	greedy = 0;
	if (!ft_sorted(stack_a))
		push_to_b(stack_a, stack_b);
	while (stack_b->size)
	{
		greedy = greedy_choice(stack_a, stack_b);
		top_to_b(stack_b, greedy);
		insert_in_a(stack_a, stack_b, greedy);
	}
	ft_surface(stack_a);
}
