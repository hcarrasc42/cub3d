/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/01 12:02:45 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	getrgb(int r, int g, int b)
{
	return (b + g * 256 + r * 256 * 256);
}

int	get_colors(char	*str)
{
	char	**numbers;
	int		rgb[3];

	str = ft_substr(str, 2, ft_strlen(str) - 1);
	numbers = ft_split(str, ',');
	rgb[0] = ft_atoi(numbers[0]);
	rgb[1] = ft_atoi(numbers[1]);
	rgb[2] = ft_atoi(numbers[2]);
	ft_doublefree(numbers);
	free(str);
	return (getrgb(rgb[0], rgb[1], rgb[2]));
}

void	crt_image(double x, t_in *in, t_grid *grid)
{
	grid->or_x = (int)x;
	grid->map_x = (int)grid->pos_x;
	grid->map_y = (int)grid->pos_y;
	init_ray_dis(grid, x, grid->vec);
	step_comp_calc(grid, grid->vec);
	grid->vec->axe = get_wall(in->map, grid, grid->vec);
	if (grid->vec->axe == 0)
		grid->vec->short_wall_dist
			= ((grid->vec->sidedist_x) - grid->vec->deltadist_x);
	else
		grid->vec->short_wall_dist
			= ((grid->vec->sidedist_y) - grid->vec->deltadist_y);
	get_height(grid, grid->vec, grid->vec->c);
	get_speed(in->time);
	draw_ver_line(x, in, grid, grid->vec->c);
	redraw_text(in, grid, grid->vec->c);
}

void	init_image(t_in	*in)
{
	double	x;

	x = 0.;
	while (++x < (in->grid->screen_width))
		crt_image(x, in, in->grid);
}
