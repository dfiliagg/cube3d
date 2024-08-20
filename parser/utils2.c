/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/09/08 13:00:51 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

void	print_map(char **mat)
{
	int	i;
	int	j;

	i = -1;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
			write(1, &mat[i][j], 1);
		write(1, "\n", 1);
	}
}

void	error(t_game *game, char *msg)
{
	printf("Error: %s\n", msg);
	free_game(game);
}
