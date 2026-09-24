/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:20:15 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/05/17 10:42:00 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_exit_free_print(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (map->map && map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	i = 0;
	while (map->star && map->star[i])
	{
		free(map->star[i]);
		i++;
	}
	printf("%s\n", str);
	exit(1);
}

void	ft_exit_print(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	ft_print_map(t_map *map, int type)
{
	int	i;

	i = 0;
	ft_print_params(map);
	while (type == 1 && map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	while (type == 2 && map->star[i])
	{
		printf("%s\n", map->star[i]);
		i++;
	}
}

void	ft_print_params(t_map *map)
{
	printf("NO: %s\n", map->no);
	printf("SO: %s\n", map->so);
	printf("EA: %s\n", map->ea);
	printf("WE: %s\n", map->we);
	printf("F: %s\n", map->f);
	printf("C: %s\n", map->c);
}
