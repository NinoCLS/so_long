/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:05:32 by nino              #+#    #+#             */
/*   Updated: 2023/11/14 16:30:01 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	new_list = NULL;
	while (tmp)
	{
		new = ft_lstnew(f(tmp->content));
		if (!new)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new);
		tmp = tmp->next;
	}
	return (new_list);
}
