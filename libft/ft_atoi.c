/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:21:34 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/27 06:47:47 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	ret;
	t_bool			is_neg;

	is_neg = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			is_neg = 1;
		i++;
	}
	ret = 0;
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + (str[i++] - '0');
		if (ret > LONG_MAX && !is_neg)
			return (-1);
		if (ret >= (unsigned long)LONG_MAX + 1 && is_neg)
			return (0);
	}
	return (is_neg ? -ret : ret);
}
