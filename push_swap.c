/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:12:11 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/13 19:33:43 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	//t_ops	func_ops[11] = {&ft_sa, &ft_sb, &ft_ss, &ft_pa, &ft_pb, &ft_ra, &ft_rb, &ft_rr, &ft_rra, &ft_rrb, &ft_rrr};
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
	less_three(stack_a, stack_b);
}