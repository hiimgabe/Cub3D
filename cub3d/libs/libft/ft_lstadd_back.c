/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:33:20 by pmagalha          #+#    #+#             */
/*   Updated: 2024/03/13 20:55:18 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*testnode;

	if (*lst == NULL)
		*lst = new;
	else
	{
		testnode = *lst;
		while (testnode -> next != NULL)
			testnode = testnode->next;
		testnode->next = new;
	}
}
