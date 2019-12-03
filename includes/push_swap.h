/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:03:18 by akhossan          #+#    #+#             */
/*   Updated: 2019/12/03 22:38:22 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_checker
{
	t_stack			*a;
	t_stack			*b;	
	char			*line;
	char			*inst;
	char			**split;
}					t_checker;

void		dispfree(t_stack *stack);
t_stack		*new_node(int nb);
int			push(t_stack **stack, int nb);
int			peek(const t_stack *stack);
t_stack		*pop(t_stack **stack);
t_stack		*sort(t_stack **stack);
void		ft_swap(t_stack *stk);
void		rotate(t_stack **stk);
void		rrotate(t_stack **stk);
void		execute(t_stack **stk, t_stack **helper, char **instr);
void		quick_sort(t_stack **stk, t_stack **temp, int n);
void		disp_stack(t_checker arg);
void		insertion(t_checker *arg, int size);
int			is_sorted(t_stack *stk);

#endif
