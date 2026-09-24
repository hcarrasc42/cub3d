/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/28 16:46:19 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **ar)
{
	t_in		*in;

	in = malloc(sizeof(t_in));
	ft_memset(in, 0, sizeof(t_in));
	in->map = ft_valid(in->map, ac, ar);
	in_structs(in);
	in->grid->vec->c->ceiling_color = get_colors(in->map->c);
	in->grid->vec->c->floor_color = get_colors(in->map->f);
	init_image(in);
	if (!in->mlx->win || (mlx_put_image_to_window
			(in->mlx->init, in->mlx->win, in->mlx->img->img, 0, 0) < 0))
		exit(EXIT_FAILURE);
	get_hooks(in);
	mlx_loop(in->mlx->init);
	free_program(in);
	return (0);
}
