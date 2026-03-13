/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:58 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/08 16:10:14 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lstlen;
	t_list	*temp;

	lstlen = 0;
	temp = lst;
	while (temp)
	{
		lstlen++;
		temp = temp->next;
	}
	return (lstlen);
}
