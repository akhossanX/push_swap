/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:46:20 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/04 20:05:21 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	countwd(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_contains(set, s[i]))
		{
			j++;
			while (s[i] && !ft_contains(set, s[i]))
				i++;
		}
		else
			i++;
	}
	return (j);
}

static	char	*dupword(char const *s, char const *set)
{
	size_t	i;
	char	*word;

	if (!s || !set)
		return (NULL);
	i = 0;
	while (!ft_contains(set, s[i]))
		i++;
	if (!(word = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (s[i] && !ft_contains(set, s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplitset(char const *s, char const *set)
{
	size_t	wd;
	size_t	i;
	size_t	j;
	char	**arr;

	if (!s || !set)
		return (NULL);
	wd = countwd(s, set);
	if (!(arr = (char **)ft_memalloc(sizeof(char *) * (wd + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_contains(set, s[i]))
		{
			arr[j++] = dupword(&s[i], set);
			while (s[i] && !ft_contains(set, s[i]))
				i++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
