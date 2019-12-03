/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:18:23 by akhossan          #+#    #+#             */
/*   Updated: 2019/12/03 22:40:57 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		sum(t_stack *a, int depth)
{
	int		sum;

	sum = 0;
	while (a && depth--)
	{
		sum += a->nbr;
		a = a->next;
	}
	return (sum);
}

void	quick_sort(t_stack **a, t_stack **temp, int n)
{
	int		toplen;
	int		median;
	int		i;
	static int	it;
	t_stack	*node;

	if (n == 1)
		return ;
	toplen = 0;
	median = sum(*a, n) / n;// dummy median (fix later);
	i = 0;
	while (i < n)
	{
		if ((*a)->nbr <= median)// store the smaller half in b stack;
		{
			node = pop(a);
			push(temp, node->nbr);
			it++;
			free(node);
			toplen++;
		}
		else
		{
			rotate(a);
			it++;
		}
		i++;
	}
	i =  -1;
	while (++i < n - toplen)
	{
		rrotate(a);
		it++;
	}
	i = 0;
	while (i++ < toplen)
	{
		node = pop(temp);
		push(a, node->nbr);
		it++;
		free(node);
	}
	quick_sort(a, temp, toplen);//recursive call on smaller half.
	i = -1;
	while (++i < toplen)
	{
		it++;
		rotate(a);
	}
	quick_sort(a, temp, n - toplen);//recursive call on larger half
	i = -1;
	while (++i < toplen)
	{
		it++;
		rrotate(a);
	}
	printf("it: %d\n", it);
}
