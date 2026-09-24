/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:11:55 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/01 11:00:39 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_cam_left(t_in	*in)
{
	double	temp;

	temp = in->grid->dir_x;
	in->grid->dir_x = (in->grid->dir_x * cos(-in->time->r_speed))
		- (in->grid->dir_y * sin(-in->time->r_speed));
	in->grid->dir_y = (temp * sin(-in->time->r_speed))
		+ (in->grid->dir_y * cos(-in->time->r_speed));
	temp = in->grid->plane_x;
	in->grid->plane_x = (in->grid->plane_x
			* cos(-in->time->r_speed)) - (in->grid->plane_y
			* sin(-in->time->r_speed));
	in->grid->plane_y = (temp * sin(-in->time->r_speed))
		+ (in->grid->plane_y * cos(-in->time->r_speed));
}

void	move_cam_right(t_in	*in)
{
	double	temp;

	temp = in->grid->dir_x;
	in->grid->dir_x = (in->grid->dir_x * cos(in->time->r_speed))
		- (in->grid->dir_y * sin(in->time->r_speed));
	in->grid->dir_y = (temp * sin(in->time->r_speed))
		+ (in->grid->dir_y * cos(in->time->r_speed));
	temp = in->grid->plane_x;
	in->grid->plane_x = (in->grid->plane_x
			* cos(in->time->r_speed)) - (in->grid->plane_y
			* sin(in->time->r_speed));
	in->grid->plane_y = (temp * sin(in->time->r_speed))
		+ (in->grid->plane_y * cos(in->time->r_speed));
}
