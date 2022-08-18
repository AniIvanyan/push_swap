/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_statistics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:44:57 by aivanyan          #+#    #+#             */
/*   Updated: 2022/08/18 21:57:57 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;
	

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_partition(int *arr, int p, int r)
{
	int	x;
	int	i;
	int	j;

	x = arr[r];
	i = p;
	j = p;
	while (j <= r - 1)
	{
		if (arr[j] <= x)
		{
			ft_swap(&(arr[i]), &(arr[j]));
			i++;
		}
		j++;
	}
	ft_swap(&(arr[i]), &(arr[r]));
	return (i);
}

int	ft_select(int *arr, int p, int r, int i)
{
	int	pivot;
	int	k;
	
	pivot = ft_partition(arr, p, r);
	k = pivot - p + 1;
	if (i == k)
		return (arr[pivot]);
	if (i < k)
		return ft_select(arr, p, pivot - 1, i);
	return ft_select(arr, pivot + 1, r, i - k);
}