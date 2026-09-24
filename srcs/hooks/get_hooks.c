/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:34:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/01 10:56:02 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	keyhook(int keydata, t_in	*in)
{
	if (keydata == MAIN_ESC)
		free_program(in);
	else if (keydata == W_KEY)
		move_front(in);
	else if (keydata == S_KEY)
		move_back(in);
	else if (keydata == D_KEY)
		move_right(in);
	else if (keydata == A_KEY)
		move_left(in);
	else if (keydata == ARROW_LEFT)
		move_cam_left(in);
	else if (keydata == ARROW_RIGHT)
		move_cam_right(in);
	else if (keydata == KEY_1)
		change_floor_color(in);
	else if (keydata == KEY_2)
		change_ceiling_color(in);
	else
		return (1);
	init_image(in);
	mlx_put_image_to_window
		(in->mlx->init, in->mlx->win, in->mlx->img->img, 0, 0);
	return (0);
}

void	get_hooks(t_in	*in)
{
	mlx_hook(in->mlx->win, 2, 1L << 0, keyhook, in);
	mlx_hook(in->mlx->win, 17, 0, free_program, in);
}
