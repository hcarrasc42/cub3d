/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:56:23 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/01 14:41:41 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*trim_dir(char	*str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i++])
		if (str[i] == '.')
			break ;
	if (str[i])
		return (ft_substr(str, i, len - i + 1));
	else
		return (NULL);
}
