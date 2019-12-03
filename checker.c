/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:59:39 by akhossan          #+#    #+#             */
/*   Updated: 2019/12/03 22:39:43 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*g_instructions[] =
{
	"sa",\
	"sb",\
	"ss",\
	"pa",\
	"pb",\
	"ra",\
	"rb",\
	"rr",\
	"rra",\
	"rrb",\
	"rrr",
};

void	ft_puterror(void)
{
	ft_putendl("Error");
	exit(1);
}

int		is_numeric(char *s)
{
	while (*s)
	{
		if (*s == '-' || *s == '+' || ft_isdigit(*s))
			s++;
		else
			return (0);
	}
	return (1);
}

int		safe_stack(int ac, char **args)
{
	long x;

	while (--ac > 0)
	{
		if (!is_numeric(args[ac]))
			return (0);
		x = ft_atol(args[ac]);
		if (x < INT_MIN || x > INT_MAX)
			return (0);
	}
	return (1);
}

int		is_instruction(char *line)
{
	int		i;

	i = 0;
	while (g_instructions[i])
	{
		if (!ft_strcmp(line, g_instructions[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fstrjoin(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (joined)
	{
		free(s1);
		free(s2);
	}
	return (joined);
}

t_stack	*make_stack(int ac, char **av)
{
	t_stack	*stk;

	stk = NULL;
	while (--ac > 0)
	{
		if (!push(&stk, ft_atoi(av[ac])))
			return (NULL);
	}
	return (stk);
}

int		is_asc_sorted(t_stack *stk)
{
	int		max;

	max = stk->nbr;
	while (stk)
	{
		if (max > stk->nbr)
			return (0);
		max = stk->nbr;
		stk = stk->next;
	}
	return (1);
}

int		is_desc_sorted(t_stack *stk)
{
	int		min;

	min = stk->nbr;
	while (stk)
	{
		if (min < stk->nbr)
			return (0);
		min = stk->nbr;
		stk = stk->next;
	}
	return (1);
}

int		is_sorted(t_stack *stk)
{
	if (is_desc_sorted(stk))
		return (-1);
	else if (is_asc_sorted(stk))
		return (1);
	return (0);
}

void	destroy_stack(t_stack **stk)
{
	t_stack	*tmp;

	while (*stk)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	del_strings(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int		stack_size(t_stack *stk)
{
	int		size;

	size = 0;
	while (stk && ++size)
		stk = stk->next;
	return (size);
}

void	disp_stack(t_checker arg)
{
	t_stack	*a;
	t_stack	*b;

	a = arg.a;
	b = arg.b;
	while (a || b)
	{
		if (a && b)
			printf("|%5d|\t\t|%5d|\n", a->nbr, b->nbr);
		else if (a)
			printf("|%5d|\t\t|%5s|\n", a->nbr, " ");
		else if (b)
			printf("|%5s|\t\t|%5d|\n", " ", b->nbr);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

int		main(int ac, char **av)
{
	t_checker	arg;

	if (!safe_stack(ac, av))
		ft_puterror();
	if (ac == 1 || !(arg.inst = ft_strnew(0)))
		exit(1);
	while (get_next_line(0, &arg.line) > 0)
	{
		if (!is_instruction(arg.line))
			ft_puterror();
		arg.inst = ft_fstrjoin(arg.inst, arg.line);
		arg.inst = ft_fstrjoin(arg.inst, ft_strdup(" "));
	}
	if (!(arg.split = ft_strsplit(arg.inst, ' ')))
		exit(1);
	if (!(arg.a = make_stack(ac, av)))
		exit(1);
	arg.b = NULL;
	disp_stack(arg);
	printf("\n");
	//execute(&arg.a, &arg.b, arg.split);
	quick_sort(&arg.a, &arg.b, stack_size(arg.a));
	disp_stack(arg);
	is_sorted(arg.a) == 1 && !arg.b ? ft_putendl("OK") : ft_putendl("KO");
	destroy_stack(&arg.a);
	destroy_stack(&arg.b);
	del_strings(arg.split);
	ft_strdel(&arg.inst);
	return (0);
}
