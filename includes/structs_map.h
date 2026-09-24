/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:03:25 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 11:03:53 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_MAP_H
# define STRUCTS_MAP_H

typedef struct s_map
{
	char	**star;
	char	**file;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	typ;
	int		hei;
	int		wid;
	int		pla;
	int		x;
	int		y;
}	t_map;

#endif