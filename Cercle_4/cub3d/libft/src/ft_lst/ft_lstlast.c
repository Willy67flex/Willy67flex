/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:19:46 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 16:10:49 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*toreturn;

	if (!lst)
		return (0);
	toreturn = lst;
	while (toreturn->next)
		toreturn = toreturn->next;
	return (toreturn);
}
