/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:23:18 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/01 10:59:38 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_front(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x + fabs(in->grid->dir_x) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x += fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x - fabs(in->grid->dir_x) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x -= fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)(in->grid->pos_y + fabs(in->grid->dir_y)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += fabs(in->grid->dir_y) * in->time->m_speed;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)(in->grid->pos_y - fabs(in->grid->dir_y)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= fabs(in->grid->dir_y) * in->time->m_speed;
}

void	move_left(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)(in->grid->pos_y - fabs(in->grid->dir_x)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)(in->grid->pos_y + fabs(in->grid->dir_x)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x - fabs(in->grid->dir_y) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x -= fabs(in->grid->dir_y) * in->time->m_speed;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x + fabs(in->grid->dir_y) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x += fabs(in->grid->dir_y) * in->time->m_speed;
}

void	move_right(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)(in->grid->pos_y + fabs(in->grid->dir_x)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)(in->grid->pos_y - fabs(in->grid->dir_x)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x + fabs(in->grid->dir_y) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x += fabs(in->grid->dir_y) * in->time->m_speed;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x - fabs(in->grid->dir_y) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x -= fabs(in->grid->dir_y) * in->time->m_speed;
}

void	move_back(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x - fabs(in->grid->dir_x) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x -= fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)in->grid->pos_y]
			[(int)(in->grid->pos_x + fabs(in->grid->dir_x) * in->time->m_speed)]
			!= '1')
			in->grid->pos_x += fabs(in->grid->dir_x) * in->time->m_speed;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)(in->grid->pos_y - fabs(in->grid->dir_y)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= fabs(in->grid->dir_y) * in->time->m_speed;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)(in->grid->pos_y + fabs(in->grid->dir_y)
				* in->time->m_speed)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += fabs(in->grid->dir_y) * in->time->m_speed;
}
