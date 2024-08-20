/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:48:11 by adi-fort          #+#    #+#             */
/*   Updated: 2023/07/25 12:51:32 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str(char	**str)
{
	if (str)
		free(*str);
	*str = NULL;
}

void	free_mat(char	***mat)
{
	int	i;

	i = 0;
	while (*mat && (*mat)[i])
	{
		free_str(&((*mat)[i]));
		i++;
	}
	*mat = NULL;
}

int	ft_map_len(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		;
	return (y);
}
