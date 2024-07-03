/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:43:14 by pmagalha          #+#    #+#             */
/*   Updated: 2024/02/06 18:30:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dest;
	char		*char_src;

	char_dest = (char *) dest;
	char_src = (char *) src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
/*
int	main (void)
{
	// Testing with strings (works with null) 
	char src[] = "copy this";
	char dest[100];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);

	//Testing to see if pointer address in dest_ptr and dest are the same
	char *dest_ptr = ft_memcpy(dest, src, strlen(src) + 1);
	printf("dest_ptr: %p\n", dest_ptr);
	printf("dest: %p\n", dest);

	// Testing with arrays
	double src_array [5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double dest_array[5];

	ft_memcpy(dest_array, src_array, sizeof(src_array));

	int 	i;

	i = 0;
	while (i < 5)
	{
		printf("dest_array[%d] = %f\n", i, dest_array[i]);
		i++;
	}
	return (0);
}*/
