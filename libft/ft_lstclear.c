/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:57:16 by nino              #+#    #+#             */
/*   Updated: 2023/11/14 14:51:51 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		tmp = begin->next;
		ft_lstdelone(begin, del);
		begin = tmp;
	}
	*lst = NULL;
}
