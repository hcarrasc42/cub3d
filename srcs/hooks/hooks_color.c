/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:54:18 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/01 10:31:14 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	change_floor_color(t_in *in)
{
	in->grid->vec->c->floor_color *= 2;
}

void	change_ceiling_color(t_in *in)
{
	in->grid->vec->c->ceiling_color *= 2;
}
