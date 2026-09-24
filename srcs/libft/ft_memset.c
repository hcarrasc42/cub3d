/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:43:17 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 10:45:08 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*content;
	int				number2;
	unsigned char	convert;

	content = (char *)b;
	number2 = 0;
	convert = c - '0';
	while (len > 0)
	{
		content[number2] = convert + '0';
		len--;
		number2++;
	}
	return (content);
}
