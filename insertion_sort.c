/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:51:04 by akhossan          #+#    #+#             */
/*   Updated: 2019/12/03 21:51:16 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_value(t_stack *a, int *min, int *pos)
{
	int		i;

	*min = INT_MAX;
	i = 0;
	while (a)
	{
		if (a->nbr < *min)
		{
			*min = a->nbr;
			*pos = i; 
		}
		a = a->next;
		i++;
	}
}

int		invert_sort(t_checker *arg)
{
	t_stack	**a;
	t_stack	**b;
	int		i;

	a = &(arg->a);
	b = &(arg->b);
	push(b, pop(a)->nbr);
	disp_stack(*arg);printf("\n");
	i = 0;
	while (*a)
	{
		push(b, pop(a)->nbr);
		rotate(b);
		i += 2;
	}
	disp_stack(*arg);printf("\n");
	while (*b)
	{
		push(a, pop(b)->nbr);
		i++;
	}
	disp_stack(*arg);printf("\n");
	return (i);
}

void	insertion(t_checker *arg, int size)
{
	int		min;
	int		i;
	int		pos;
	int		b_items;
	int		j;
	int		actions;
	t_stack	**a;
	t_stack **b;
	int		is_sort;

	a = &(arg->a);
	b = &(arg->b);
	//Trivial fucking shit method *_*
	i = 0;
	pos = 0;
	b_items = 0;
	printf("size: %d\n", size);
	actions = 0;
	is_sort = is_sorted(*a);
	if (!is_sort)
		while (*a && size - 3 > 0)
		{
			get_min_value(*a, &min, &pos);
			printf("min: %d\n", min);
			printf("pos: %d\n", pos);
			j = -1;
			if (pos > (size - b_items) / 2)
				while (++j < size - pos && ++actions)
					rrotate(a);
			else
				while (++j < pos && ++actions)
					rotate(a);
			//printf("nbr: %d\n", (*a)->nbr);
			//exit(1);
			push(b, pop(a)->nbr);
			++actions;
			size--;
			i++;
			disp_stack(*arg);
			printf("\n");
		}
	else if (is_sort == -1)
	{
		printf("inverted\n");
		actions += invert_sort(arg);
	}
	else
		return ;
	printf("before pushing back to A\n");
	/*
	**	simple insertion sort of 3 integers;
	*/
	if ((*a)->next->nbr < (*a)->nbr && ++actions)
		ft_swap(*a);
	int	cmp = (*a)->next->next->nbr;
	if (cmp < (*a)->next->nbr && ++actions)
	{
		ft_swap((*a)->next);
		if (cmp < (*a)->nbr && ++actions)
			ft_swap(*a);	
	}
	while (*b && ++actions)
		push(a, pop(b)->nbr);
	printf("actions: %d\n", actions);
}

