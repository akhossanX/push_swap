/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:23:26 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/30 09:54:22 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*tmp;

	ptr = NULL;
	tmp = (char *)s;
	while ((tmp = ft_strchr(tmp, c)))
	{
		if (!(*tmp))
			return (tmp);
		ptr = tmp;
		tmp++;
	}
	return (ptr);
}
