/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:41:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/28 16:39:45 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_atoi(const char *str)
{
	int				loop;
	unsigned int	box;
	int				negative;

	box = 0;
	loop = 0;
	negative = 1;
	while (str[loop] == '\n' || str[loop] == '\t' || str[loop] == '\v'
		|| str[loop] == ' ' || str[loop] == '\f' || str[loop] == '\r')
		loop++;
	if (str[loop] == '-' || str[loop] == '+')
	{
		if (str[loop++] == '-')
		{
			negative = -negative;
		}
	}
	while (str[loop] >= '0' && str[loop] <= '9')
	{
		box = (box * 10) + str[loop] - '0';
		loop++;
	}
	return ((int)(box * negative));
}
