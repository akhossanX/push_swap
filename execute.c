/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 06:26:04 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/28 13:25:13 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_exec(t_stack **stk, t_stack **helper, char *split)
{
	if (!ft_strcmp(split, "sa"))
		ft_swap(*stk);
	else if (!ft_strcmp(split, "sb"))
		ft_swap(*helper);
	else
	{
		ft_swap(*stk);
		ft_swap(*helper);
	}
}

static void	push_exec(t_stack **stk, t_stack **helper, char *split)
{
	t_stack	*elem;

	elem = !ft_strcmp(split, "pa") ? pop(helper) : pop(stk);
	if (!elem)
		return ;
	if (!ft_strcmp(split, "pa"))
		push(stk, elem->nbr);
	else
		push(helper, elem->nbr);
	free(elem);
}

static void	rotate_exec(t_stack **stk, t_stack **helper, char *split)
{
	if (!ft_strcmp(split, "ra") && *stk)
		rotate(stk);
	else if (!ft_strcmp(split, "rb") && *helper)
		rotate(helper);
	else if (*stk && *helper)
	{
		rotate(stk);
		rotate(helper);
	}
}

static void	rrotate_exec(t_stack **stk, t_stack **helper, char *split)
{
	if (!ft_strcmp(split, "rra") && *stk)
		rrotate(stk);
	else if (!ft_strcmp(split, "rrb") && *helper)
		rrotate(helper);
	else if (*stk && *helper)
	{
		rrotate(stk);
		rrotate(helper);
	}
}

void		execute(t_stack **stk, t_stack **helper, char **split)
{
	int		i;
	char	*s;

	i = 0;
	while (split[i])
	{
		s = split[i];
		if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") ||\
				!ft_strcmp(s, "ss"))
			swap_exec(stk, helper, s);
		else if (!ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
			push_exec(stk, helper, s);
		else if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") ||\
				!ft_strcmp(s, "rr"))
			rotate_exec(stk, helper, s);
		else
			rrotate_exec(stk, helper, s);
		i++;
	}
}
