/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:42:56 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 14:23:42 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(void)
{
	game()->map = ft_calloc(1, sizeof(t_map));
	if (!game()->map)
	{
		//eventually free_game
		error_exit("Mem alloc error.\n");
	}
}
