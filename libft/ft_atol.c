/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 04:13:28 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/27 04:21:57 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
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
		ret = ret * 10 + (str[i++] - '0');
	return (is_neg ? -ret : ret);
}
