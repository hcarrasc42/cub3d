/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/01 10:49:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	in_dir(t_grid *grid, t_map *map)
{
	if (map->typ == 'N')
	{
		grid->dir_y = -1.;
		grid->plane_x = 0.66;
	}
	else if (map->typ == 'W')
	{
		grid->dir_x = -1.;
		grid->plane_y = -0.66;
	}
	else if (map->typ == 'E')
	{
		grid->dir_x = 1.;
		grid->plane_y = 0.66;
	}
	else if (map->typ == 'S')
	{
		grid->dir_y = 1.;
		grid->plane_x = -0.66;
	}
}

void	in_grid(t_grid	*grid, t_map *map)
{
	grid->vec = malloc(sizeof(t_vector));
	ft_memset(grid->vec, 0, sizeof(t_vector));
	grid->vec->c = malloc(sizeof(t_colors));
	ft_memset(grid->vec->c, 0, sizeof(t_colors));
	grid->screen_height = 1080;
	grid->screen_width = 1920;
	in_dir(grid, map);
	grid->pos_x = map->x - 1;
	grid->pos_y = map->y - 1;
	map->x -= 1;
	map->y -= 1;
}

int	*load_xpm(void *img, t_in	*in, char	*dir)
{
	int		x;
	int		y;
	int		*pix;

	y = 64;
	x = 64;
	img = mlx_xpm_file_to_image(in->mlx->init, dir, &x, &y);
	if (!img)
	{
		perror("Error : XPM file not correct");
		exit (1);
	}
	pix = (int *)mlx_get_data_addr(img, &in->mlx->img->bits_ppixel,
			&in->mlx->img->line_length, &in->mlx->img->endian);
	free(dir);
	return (pix);
}

void	in_mlx(t_in	*in, t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(in->mlx->init, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	mlx->img->img = mlx_new_image(in->mlx->init,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->img->add = (int *)mlx_get_data_addr(in->mlx->img->img,
			&in->mlx->img->bits_ppixel,
			&in->mlx->img->line_length, &in->mlx->img->endian);
	if (!in->mlx->img->img)
		exit (EXIT_FAILURE);
	in->textures->add_north = load_xpm
		(in->textures->img_north, in, trim_dir(in->map->no));
	in->textures->add_east = load_xpm
		(in->textures->img_east, in, trim_dir(in->map->ea));
	in->textures->add_west = load_xpm
		(in->textures->img_west, in, trim_dir(in->map->we));
	in->textures->add_south = load_xpm
		(in->textures->img_south, in, trim_dir(in->map->so));
}

void	in_structs(t_in *in)
{
	in->mlx = malloc(sizeof(t_mlx));
	ft_memset(in->mlx, 0, sizeof(t_mlx));
	in->mlx->img = malloc(sizeof(t_img));
	ft_memset(in->mlx->img, 0, sizeof(t_img));
	in->textures = malloc(sizeof(t_text));
	ft_memset(in->textures, 0, sizeof(t_text));
	in_mlx(in, in->mlx);
	in->grid = malloc(sizeof(t_grid));
	ft_memset(in->grid, 0, sizeof(t_grid));
	in_grid(in->grid, in->map);
	in->time = malloc(sizeof(t_time));
	ft_memset(in->time, 0, sizeof(t_time));
}
