/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:54:41 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/31 15:20:46 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (tmp_dst < tmp_src)
	{
		i = 0;
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while ((int)(--len) >= 0)
			tmp_dst[i + len] = tmp_src[len];
	}
	return (dst);
}
