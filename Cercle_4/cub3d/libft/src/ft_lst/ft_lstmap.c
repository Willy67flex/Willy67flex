/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:10:09 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 16:19:47 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*toreturn;
	t_list	*obj;

	if (!lst || !f || !del)
		return (0);
	toreturn = NULL;
	while (lst)
	{
		obj = ft_lstnew(f(lst->content));
		if (!obj)
		{
			ft_lstclear(&obj, del);
			return (NULL);
		}
		ft_lstadd_back(&toreturn, obj);
		lst = lst->next;
	}
	return (toreturn);
}
