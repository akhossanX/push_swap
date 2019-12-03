/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:34:23 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/01 20:17:37 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	char const	*s_end;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	s_end = s + ft_strlen(s) - 1;
	while (ft_isspace(*s_end))
		s_end--;
	return (ft_strsub(s, 0, s_end - s + 1));
}
