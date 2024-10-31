/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:42:19 by gabe              #+#    #+#             */
/*   Updated: 2024/10/22 12:51:27 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	start_ray(t_ray *ray, int x)
{
	double		cam_x;
	t_player	player;

	player = game()->player;
	cam_x = 2 * (double)x / SCREEN_W - 1;
	ray->pos = convert_to_map(player.pos);
	ray->dir.x = player.dir.x + player.cam.x * cam_x;
	ray->dir.y = player.dir.y + player.cam.y * cam_x;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	set_side_dist(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - (int)ray->pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((int)ray->pos.x + 1 - ray->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - (int)ray->pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((int)ray->pos.y + 1 - ray->pos.y)
			* ray->delta_dist.y;
	}
}

static void	dda(t_ray *ray)
{
	bool	wall_hit;

	wall_hit = false;
	while (!wall_hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else if (ray->side_dist.x > ray->side_dist.y)
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (is_wall(game()->map->layout[(int)ray->pos.y][(int)ray->pos.x]))
			wall_hit = true;
	}
}

static void	calc_line_height(t_ray *ray)
{
	t_pos	curr;

	curr = convert_to_map(game()->player.pos);
	if (!ray->side)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(SCREEN_W / ray->perp_wall_dist);
	ray->start = -ray->line_height / 2 + SCREEN_W / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_height / 2 + SCREEN_W / 2;
	if (ray->end > SCREEN_W)
		ray->end = SCREEN_W - 1;
	if (!ray->side)
		ray->wall_x = curr.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = curr.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycast(void)
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < SCREEN_W)
	{
		start_ray(&ray, x);
		set_side_dist(&ray);
		dda(&ray);
		calc_line_height(&ray);
		render_texture(&ray, x);
	}
}
