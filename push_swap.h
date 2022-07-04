/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:29:53 by aivanyan          #+#    #+#             */
/*   Updated: 2022/07/04 22:29:22 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
typedef struct	s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}				t_stack;

// stack_utils
t_stack *ft_stk_construct();

//stack_ops
void	ft_sa(t_stack *a, t_stack *b);
void	ft_sb(t_stack *a, t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
#endif