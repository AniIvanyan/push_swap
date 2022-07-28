/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:12:11 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/28 17:52:28 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = ft_stk_construct();
	stack_b = ft_stk_construct();
	i = argc - 1;
	while (i > 0)
	{
	 	ft_stk_push_int(stack_a, ft_atoi(argv[i--]));
	}
	i = argc - 1;
	while(i > 0)
	{
	printf("%i\n",stack_a->head->data);
	stack_a->head = stack_a->head->next;
	i--;
	}
	if (stack_a->size <= 5)
		less_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
	i = argc - 1;
	while(i > 0)
	{
	printf("%i\n",stack_a->head->data);
	stack_a->head = stack_a->head->next;
	i--;
	}
}