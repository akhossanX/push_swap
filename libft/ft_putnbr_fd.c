/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:03:38 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/04 19:39:14 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		if (nb == INT_MIN)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb / 10 == 0)
	{
		ft_putchar_fd(nb + '0', fd);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
