/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:42:19 by gabe              #+#    #+#             */
/*   Updated: 2024/10/08 15:38:24 by gabe             ###   ########.fr       */
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
	//printf("===============================================\n");
	//printf("x %d\n", x);
	//printf("game()->player y %f x %f\n", game()->player.pos.y, game()->player.pos.x);
	//printf("player y %f x %f\n", player.pos.y, player.pos.x);
	//printf("cam_x %f\n", cam_x);
	//printf("ray->pos y %f x %f\n", ray->pos.y, ray->pos.x);
	//printf("ray->dir y %f x %f\n", ray->dir.y, ray->dir.x);
}

static void	set_delta_dist(t_ray *ray)
{
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	//printf("ray->delta dist y %f x %f\n", ray->delta_dist.y, ray->delta_dist.x);
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
		ray->side_dist.x = ((int)ray->pos.x + 1 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - (int)ray->pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((int)ray->pos.y + 1 - ray->pos.y) * ray->delta_dist.y;
	}
	//printf("ray->dir y %f x %f\n", ray->dir.y, ray->dir.x);
	//printf("ray->step y %f x %f\n", ray->step.y, ray->step.x);
	//printf("ray->side dist y %f x %f\n", ray->side_dist.y, ray->side_dist.x);
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
	//printf("ray->side dist y %f x %f\n", ray->side_dist.y, ray->side_dist.x);
	//printf("ray->pos y %f x %f\n", ray->pos.y, ray->pos.x);
	//printf("ray->side %d\n", ray->side);
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

void	set_texture_index(t_ray *ray)
{
	if (!ray->side)
	{
		if (ray->dir.x < 0)
			game()->texture_info->index = WEST;
		else
			game()->texture_info->index = EAST;
	}
	else
	{
		if (ray->dir.y < 0)
			game()->texture_info->index = NORTH;
		else
			game()->texture_info->index = SOUTH;
	}
}

void	render_texture(t_ray *ray, int x)
{
	t_texture_info	*text;
	int				y;
	int				color;

	text = game()->texture_info;
	set_texture_index(ray);
	text->x = (int)(ray->wall_x * (double)text->size);
	text->step = (double)text->size / ray->line_height;
	text->pos = (ray->start - (double)SCREEN_W / 2 + (double)ray->line_height / 2) * text->step;
	y = ray->start;
	while (y < ray->end)
	{
		text->y = (int)text->pos & (text->size - 1);
		text->pos += text->step;
		color = game()->textures[text->index][text->size * text->y + text->x];
		if (text->index == SOUTH || text->index == NORTH)
			color = (color >> 1) & 8355711;
		color = shader(ray->perp_wall_dist, color);
		render_pixel((t_pos){x, y}, color);
		y++;
	}
}

void	raycast()
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < SCREEN_W)
	{
		start_ray(&ray, x);
		set_delta_dist(&ray);
		set_side_dist(&ray);
		dda(&ray);
		calc_line_height(&ray);
		render_texture(&ray, x);
	}
} 