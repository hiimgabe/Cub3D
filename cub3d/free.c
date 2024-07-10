/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:22:08 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/10 10:25:11 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_map(t_map *map)
{
    int i = 0;

    if (map->layout)
    {
        while (map->layout[i])
        {
            free(map->layout[i]);
            i++;
        }
        free(map->layout);
    }
}

void free_game(t_game *game)
{
    if (game)
    {
        if (game->map)
        {
            free_map(game->map);
            free(game->map);
        }
        free(game);
    }
}