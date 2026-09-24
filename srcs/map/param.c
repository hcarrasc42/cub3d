/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:08:46 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/08/28 16:04:18 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_get_file(t_map *map, char *file)
{
	int		fd;
	char	*aux;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	aux = ft_strjoin(line, "");
	line = get_next_line(fd);
	while (line)
	{
		aux = ft_strjoin(aux, line);
		free (line);
		line = get_next_line(fd);
	}
	map->file = ft_split(aux, '\n');
	free (aux);
}

int	ft_check_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && str[i] != 'F' && str[i] != 'C')
	{
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_save_map(t_map *map, char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	map->map = (char **)malloc(sizeof(char *) * (len + 1));
	while (str[i] && i < len)
	{
		j = 0;
		map->map[i] = (char *)malloc((ft_strlen(str[i]) + 1));
		while (str[i][j])
		{
			map->map[i][j] = str[i][j];
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	map->map[i] = NULL;
}

void	ft_get_params_map(t_map *map)
{
	int		i;
	char	**aux;

	i = 0;
	aux = map->file;
	while (aux[i] && ft_check_one(aux[i]))
	{
		if (!ft_strncmp(aux[i], "NO", 2))
			map->no = aux[i];
		else if (!ft_strncmp(aux[i], "SO", 2))
			map->so = aux[i];
		else if (!ft_strncmp(aux[i], "EA", 2))
			map->ea = aux[i];
		else if (!ft_strncmp(aux[i], "WE", 2))
			map->we = aux[i];
		else if (!ft_strncmp(aux[i], "F", 1))
			map->f = aux[i];
		else if (!ft_strncmp(aux[i], "C", 1))
			map->c = aux[i];
		i++;
	}
	ft_save_map(map, aux + i);
}

void	ft_check_params(t_map *map)
{
	if (!map->no)
		ft_exit_free_print("Error: North texture", map);
	if (!map->so)
		ft_exit_free_print("Error: South texture", map);
	if (!map->ea)
		ft_exit_free_print("Error: East texture", map);
	if (!map->we)
		ft_exit_free_print("Error: West texture", map);
	if (!map->f)
		ft_exit_free_print("Error: Flor color", map);
	if (!map->c)
		ft_exit_free_print("Error: Ceiling color", map);
}
