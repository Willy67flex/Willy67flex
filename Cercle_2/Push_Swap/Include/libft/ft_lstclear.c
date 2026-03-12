/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:09:55 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/09 14:03:05 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tps;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tps = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tps;
	}
	*lst = NULL;
}
