/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:34:52 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/27 21:14:42 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stk)
{
	t_stack	*elem1;
	t_stack	*elem2;
	int		tmp;

	elem1 = stk;
	elem2 = stk->next;	
	if (!elem1 || !elem2)
		return ;
	tmp = elem1->nbr;
	elem1->nbr = elem2->nbr;
	elem2->nbr = tmp;
}

void	rotate(t_stack **stk)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stk)->next)
		return ;
	last = *stk;	
	first = (*stk)->next;
	while ((*stk)->next)
		*stk = (*stk)->next;
	(*stk)->next = last;
	last->next = NULL;
	*stk = first;
}

void	rrotate(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack *last;

	if (!(*stk)->next)
		return ;
	tmp = *stk;
	last = *stk;
	while (tmp->next)
	{
		if (!tmp->next->next)
			last = tmp;
		tmp = tmp->next;	
	}
	first = tmp;
	first->next = *stk;
	last->next = NULL;
	*stk = first;
}
