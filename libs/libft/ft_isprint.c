/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:46:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/04/27 10:31:04 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*

#include <stdio.h>

int main()
{
    char c = 'a';

    if (ft_isprint(c))
        printf("%c is printable\n", c);
    else
        printf("%c is not printable\n", c);

    c = '\t';

    if (ft_isprint(c))
        printf("%c is printable\n", c);
    else
        printf("%c is not printable\n", c);

    return 0;
}*/
