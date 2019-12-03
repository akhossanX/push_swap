/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:13:46 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/04 21:08:42 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies f to each node of the linked list
** the function f returns a pointer to list
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = (*f)(lst);
	current = head;
	while (lst && lst->next)
	{
		current->next = (*f)(lst->next);
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
