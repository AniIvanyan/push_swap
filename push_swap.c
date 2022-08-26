/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:12:11 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/26 13:23:59 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_stack_push(t_stack *stack_a, char **argv, int i, int j)
{
	while (i > 0)
	{
		j = ft_strlen(argv[i]) - 1;
		if (ft_isempty(argv[i]) || ft_invalidsign(argv[i]) || j == -1)
			ft_exit();
		while (j >= 0)
		{
			if (ft_isdigit(argv[i][j]) && (ft_issign(argv[i][j - 1]) 
				|| ft_isspace(argv[i][j - 1]) || j == 0))
			{
				if (j == 0 && ft_isnumeric(&argv[i][j], j))
					ft_stk_push_int(stack_a, ft_atoi(&argv[i][j]));
				else if (ft_isnumeric(&argv[i][j - 1], j - 1))
					ft_stk_push_int(stack_a, ft_atoi(&argv[i][j - 1]));
				else
					ft_exit();
			}
			else if (!ft_isnumeric(&argv[i][j], j))
				ft_exit();
			j--;
		}
		i--;
	}
}

static void	ft_fill_array(int *arr, t_node *head, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = head->data;
		head = head->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	int	*arr;
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return (0);
	stack_a = ft_stk_construct();
	stack_b = ft_stk_construct();
	ft_stack_push(stack_a, argv, argc - 1, 0);
	argc = stack_a->size;
	arr = malloc(argc * sizeof(int));
	if (!arr)
		return (0);
	ft_fill_array(arr, stack_a->head, argc);
	if (argc <= 5)
	 	less_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, ft_select(arr, 0, argc - 1, argc / 2));
	free(arr);
}
