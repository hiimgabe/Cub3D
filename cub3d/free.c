/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:22:08 by pmagalha          #+#    #+#             */
/*   Updated: 2024/07/11 16:48:59 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_map(t_map *map)
{
    int i;
    
    if (map)
    {
        if (map && map->layout)
        {
            i = 0;
            while (map->layout[i])
            {
                free(map->layout[i]);
                i++;
            }
            free(map->layout);
        }
    }
    if (map->no)
        free(map->no);
    if (map->so)
        free(map->so);
    if (map->we)
        free(map->we);
    if (map->ea)
        free(map->ea);
    if (map->f)
        free(map->f);
    if (map->c)
        free(map->c);
}

void free_game()
{
    if (game()->map)
    {
        free_map(game()->map);
        free(game()->map);
        game()->map = NULL;
    }
}
