/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:02:04 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/03 18:54:43 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnew(size_t size)
{
	char	*mem;

	if (!(mem = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (mem);
}
