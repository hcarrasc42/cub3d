/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:07:09 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/07 11:50:21 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_check_args(int argc)
{
	if (argc != 2)
		ft_exit_print("Error: Invalid arg quantity");
}

void	ft_check_exte(char *str)
{
	int		i;
	char	*aux;

	i = 0;
	while (str[i])
		i++;
	while (str[i] >= 0 && str[i] != '.')
		i--;
	if (str[i] == '.')
	{
		aux = ft_strdup(str + i);
		if (ft_strcmp(aux, ".cub"))
		{
			free(aux);
			ft_exit_print("Error: file extension");
		}
		free(aux);
	}
	else
		ft_exit_print("Error: file extension");
}

void	ft_check_file(char *file)
{
	int		fd;
	char	buffer;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_print("Error: File not found");
	if (read(fd, &buffer, 1) == 0)
	{
		close(fd);
		ft_exit_print("Error: File is empty");
	}
	close(fd);
}

t_map	*ft_check_maps(t_map *map, char *file)
{
	map = ft_calloc(1, sizeof(t_map));
	ft_get_file(map, file);
	ft_get_params_map(map);
	ft_hei_wid(map);
	ft_wall_map(map);
	ft_check_params(map);
	ft_check_char(map);
	ft_check_walls(map, map->star, map->x, map->y);
	ft_print_map(map, 2);
	return (map);
}

t_map	*ft_valid(t_map *map, int argc, char **arg)
{
	ft_check_args(argc);
	ft_check_exte(arg[1]);
	ft_check_file(arg[1]);
	map = ft_check_maps(map, arg[1]);
	return (map);
}
