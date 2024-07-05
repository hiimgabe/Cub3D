/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:13:49 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/26 13:25:20 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (lst == NULL || del == NULL)
	{
		return ;
	}
	while (*lst)
	{
		cur = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cur;
	}
	*lst = 0;
}
