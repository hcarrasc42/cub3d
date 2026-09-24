/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:29:38 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/08/26 20:19:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_first_line(char **str, int pos, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		str[pos][i] = '*';
	str[pos][i] = '\0';
}

void	ft_put_stars(char **str, int j, int y, int len)
{
	while (y <= len)
	{
		str[j][y] = '*';
		y++;
	}
	str[j][y] = '\0';
}

void	ft_wrong_char(t_map *map, char **file, int i, int j)
{
	if (file[i][j] != '0' && file[i][j] != '1' && file[i][j] != 'N'
		&& file[i][j] != 'S' && file[i][j] != 'W' && file[i][j] != 'E'
			&& file[i][j] != '*')
	{
		printf("Line: %d\nStr: %s\n", i, file[i]);
		ft_exit_free_print("Error: Wrong character", map);
	}
}

void	ft_hei_wid(t_map *map)
{
	int	i;
	int	aux;
	int	len;

	i = 0;
	len = 0;
	map->hei = 0;
	map->wid = 0;
	while (map->map[map->hei])
		map->hei++;
	while (map->map[i])
	{
		aux = 0;
		while (map->map[i][aux])
			aux++;
		if (aux > len)
			len = aux;
		i++;
	}
	map->wid = len;
}

void	ft_set_player(t_map *map, char **file, int i, int j)
{
	if (file[i][j] == 'N' || file[i][j] == 'S' || file[i][j] == 'W'
		|| file[i][j] == 'E')
	{
		map->typ = file[i][j];
		map->pla++;
		map->x = j;
		map->y = i;
	}
}
