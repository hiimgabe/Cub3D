/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:07:37 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/28 14:00:55 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list *head;
	t_list	*add_front;

	head = ft_lstnew("ola");
	add_front = ft_lstnew("front");

	ft_lstadd_front(&head, add_front);
	printf("%s", (char *)add_front->next->content);
}
*/