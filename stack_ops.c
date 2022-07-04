/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:29:45 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/04 22:34:15 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, t_stack *b)
{
	int temp;
	
	(void)b;
	if (a->size < 2)
		return ;
	temp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = temp;
}

void	ft_sb(t_stack *a, t_stack *b)
{
	int temp;
	
	(void)a;
	if (b->size < 2)
		return ;
	temp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = temp;
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, b);
	ft_sb(a, b);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	
}