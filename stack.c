/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:09:44 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/29 15:09:00 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispfree(t_stack *stk)
{
	t_stack	*tmp;

	while (stk)
	{
		tmp = stk;
		printf("%d ", stk->nbr);
		stk = stk->next;
		free(tmp);
	}
	printf("\n");
}

t_stack	*new_node(int nb)
{
	t_stack	*node;

	if (!(node = (t_stack *) malloc(sizeof(t_stack))))
		return (0);
	node->nbr = nb;
	node->next = 0;
	return (node);
}

int		push(t_stack **stack, int elem)
{
	t_stack *new;

	if (!stack)
		return (0);
	if (!*stack)
	{
		if (!(*stack = new_node(elem)))
			return (0);
		return (1);
	}
	if (!(new = new_node(elem)))
		return (0);
	new->next = *stack;
	*stack = new;
	return (1);
}

// No check for Null stack
int	peek(const t_stack *stack)
{
	return (stack->nbr);
}

t_stack	*pop(t_stack **stack)
{
	t_stack *node;

	node = 0;
	if (!stack || !*stack)
		return (0);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	return (node);
}

t_stack	*sort(t_stack **stack)
{
	int		tmp;
	t_stack *tmp_stack;

	if (*stack == 0 || !*stack)
		return (*stack);
	tmp_stack = pop(stack);
	if (!tmp_stack)
		return (*stack);
	while (*stack)
	{
		tmp = pop(stack)->nbr;
		while (tmp_stack && tmp > peek(tmp_stack))
			push(stack, pop(&tmp_stack)->nbr);
		push(&tmp_stack, tmp);
	}
	*stack = tmp_stack;
	return (*stack);
}
