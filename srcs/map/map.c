/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:16:49 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/08/28 16:17:31 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_space_stars(char *map, char **str, int j, int y)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '\t')
			str[j][y] = '*';
		else
			str[j][y] = map[i];
		i++;
		y++;
	}
	return (y);
}

void	ft_wall_map_while(t_map *map, char **aux, int k, int j)
{
	int	y;

	while (j < (map->hei + 2))
	{
		aux[j] = malloc(sizeof(char) * (map->wid + 3));
		if (j == 0 || j == (map->hei + 1))
			ft_first_line(aux, j, map->wid + 2);
		else
		{
			y = 1;
			aux[j][0] = '*';
			y = ft_space_stars(map->map[k], aux, j, y);
			ft_put_stars(aux, j, y, map->wid + 1);
			k++;
		}
		j++;
	}
	aux[j] = NULL;
}

void	ft_wall_map(t_map *map)
{
	char	**aux;

	aux = malloc(sizeof(char *) * (map->hei + 3));
	ft_wall_map_while(map, aux, 0, 0);
	map->star = aux;
}

void	ft_check_char(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->typ = 0;
	map->pla = 0;
	while (map->star[i])
	{
		j = 0;
		while (map->star[i][j])
		{
			ft_wrong_char(map, map->star, i, j);
			ft_set_player(map, map->star, i, j);
			j++;
		}
		i++;
	}
	if (map->pla != 1)
		ft_exit_free_print("Error: Wrong player", map);
}

void	ft_check_walls(t_map *map, char **copy, int x, int y)
{
	if (copy[y][x] == 'N' || copy[y][x] == '0')
	{
		copy[y][x] = 'F';
		ft_check_walls(map, copy, x, y - 1);
		if (copy[y][x] == 'N' || copy[y][x] == '0' || copy[y][x] == 'F')
		{
			copy[y][x] = 'F';
			ft_check_walls(map, copy, x + 1, y);
			if (copy[y][x] == 'N' || copy[y][x] == '0' || copy[y][x] == 'F')
			{
				copy[y][x] = 'F';
				ft_check_walls(map, copy, x, y + 1);
				if (copy[y][x] == 'N' || copy[y][x] == '0' || copy[y][x] == 'F')
				{
					copy[y][x] = 'F';
					ft_check_walls(map, copy, x - 1, y);
				}
			}
		}
	}
	if (copy[y][x] == '*')
		ft_exit_free_print("Error: Wrong closed", map);
}
