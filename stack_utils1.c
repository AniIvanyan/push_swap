/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:01:19 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/04 22:16:37 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stk_construct(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	ft_stk_push_int(t_stack *this, int data)
{
	t_node	*new_node;
	t_node	*temp;
	int		i;

	i = 0;
	temp = this->head;
	new_node = malloc(sizeof(t_node));
	if (!this || !new_node)
		return ;
	while (i < this->size)
	{
		if (temp->data == data)
		{
			ft_putstr("Error\n");
			return ;
		}
		temp = temp->next;
		i++;
	}
	temp = this->head;
	new_node->data = data;
	ft_stk_push_node(this, new_node);
}

void	ft_stk_push_node(t_stack *this, t_node *node)
{
	if (!this || !node)
		return ;
	if (this->size == 0)
	{
		this->head = node;
		this->head->next = this->head;
		this->head->prev = this->head;
	}
	else
	{
		node->next = this->head;
		node->prev = this->head->prev;
		this->head->prev->next = node;
		this->head->prev = node;
		this->head = node;
	}
	this->size++;
}

t_node	*ft_stk_pop(t_stack *this)
{
	t_node	*old_head;
	t_node	*predecessor;
	t_node	*successor;

	if (!this || !this->size)
		return (NULL);
	old_head = this->head;
	if (this->size == 1)
	{
		this->head = NULL;
		this->size--;
		return (old_head);
	}
	predecessor = old_head->prev;
	successor = old_head->next;
	predecessor->next = successor;
	successor->prev = predecessor;
	this->head = successor;
	this->size--;
	return (old_head);
}

t_node	*ft_stk_top(t_stack *this)
{
	if (!this)
		return (NULL);
	return (this->head);
}
