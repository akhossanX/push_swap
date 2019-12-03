/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:17:50 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/09 17:21:02 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	nb_length(int nb)
{
	size_t	i;

	i = 1;
	while (nb / 10 != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	t_bool	is_neg;
	char	*number;
	int		digits;
	long	nbr;

	nbr = n;
	is_neg = (n < 0 ? 1 : 0);
	digits = nb_length(nbr);
	if (!(number = ft_strnew(digits + is_neg)))
		return (NULL);
	if (is_neg)
	{
		nbr *= -1;
		number[0] = '-';
	}
	while (digits > 0)
	{
		number[digits + is_neg - 1] = (nbr % 10) + '0';
		digits--;
		nbr /= 10;
	}
	return (number);
}
