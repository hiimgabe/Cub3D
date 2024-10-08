/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:42:21 by gabe              #+#    #+#             */
/*   Updated: 2024/09/25 14:40:15 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int key)
{
	if (key == 65307)
		exit(42);
	else if (key == 119)// W
	{
		printf("W");
		exit(42);
	}
	else if (key == 97)// A
	{
		printf("A");
		exit(42);
	}
	else if (key == 115)// S
	{
		printf("S");
		exit(42);
	}
	else if (key == 100)// D
	{
		printf("D");
		exit('D');
	}
	else if (key == 65363)// ->
	{
		printf("->");
		exit(42);
	}
	else if (key == 65361)// <-
	{
		printf("<-");
		exit(42);
	}
	return (0);
}