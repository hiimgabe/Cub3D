/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:53:13 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/28 10:43:38 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void) {
    
    int* arr = (int*)ft_calloc(10, sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
     do something with the allocated memory 
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
     free the allocated memory 
    free(arr);
    return 0;
}*/
