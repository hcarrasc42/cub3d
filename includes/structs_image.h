/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_image.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/22 11:41:39 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_IMAGE_H
# define STRUCTS_IMAGE_H

# include "structs_map.h"

typedef struct s_colors
{
	int		line_height;

	int		color_bstart;
	int		color_bend;

	int		floor_color;
	int		wall_color;
	int		ceiling_color;
	int		text_num;

	double	wall_hit;
	int		text_x;
	int		text_y;
	int		text_width;

	double	step;
	double	text_pos;
}	t_colors;

typedef struct s_vector
{
	float		raydir_x;
	float		raydir_y;

	float		sidedist_x;
	float		sidedist_y;

	float		deltadist_x;
	float		deltadist_y;

	int			step_x;
	int			step_y;

	float		short_wall_dist;
	int			axe;
	t_colors	*c;
}	t_vector;

typedef struct s_grid
{
	int			or_x;

	int			map_y;
	int			map_x;

	int			screen_height;
	int			screen_width;

	float		pos_x;
	float		pos_y;

	float		dir_x;
	float		dir_y;

	float		plane_x;
	float		plane_y;

	float		camera_x;
	float		camera_y;

	t_vector	*vec;
}	t_grid;

typedef struct s_time
{
	float		old_time;
	float		c_time;

	float		frame_rate;

	float		m_speed;
	float		r_speed;
}	t_time;

typedef struct s_text
{
	void	*img_north;
	int		*add_north;
	void	*img_east;
	int		*add_east;
	void	*img_west;
	int		*add_west;
	void	*img_south;
	int		*add_south;
}	t_text;

typedef struct s_img
{
	void	*img;
	int		*add;

	int		bits_ppixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	t_img	*img;
}	t_mlx;

typedef struct s_in
{
	t_grid			*grid;
	t_map			*map;
	t_time			*time;
	t_mlx			*mlx;
	t_text			*textures;
}	t_in;

#endif