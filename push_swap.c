/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:12:11 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/18 23:28:52 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int	*arr;
	t_stack *stack_a;
	t_stack *stack_b;

	i = argc - 1;
	arr = malloc(i * sizeof(int));
	if (!arr)
		return (0);
	while (i > 0)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i--;
	}
	i = argc - 1;
	stack_a = ft_stk_construct();
	stack_b = ft_stk_construct();
	while (i > 0)
	 	ft_stk_push_int(stack_a, ft_atoi(argv[i--]));
	i = argc - 1;
	while(i > 0)
	{
	printf("%i\n",stack_a->head->data);
	stack_a->head = stack_a->head->next;
	i--;
	}
	i = argc - 1;
	if (stack_a->size <= 5)
		less_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, ft_select(arr, 0, i - 1, i / 2));
	free(arr);
	while(i > 0)
	{
	printf("%i\n",stack_a->head->data);
	stack_a->head = stack_a->head->next;
	i--;
	}

	if (ft_sorted(stack_a))
		printf("SORTED: YAAAAY SUCCESS");
}
