/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:48:11 by adi-fort          #+#    #+#             */
/*   Updated: 2023/07/25 12:51:32 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3D.h"

int	check_n(char *str)
{
	char	*tmp;
	int		i;
	int		r;

	i = 0;
	r = 0;
	tmp = ft_strtrim(str, " \n");
	while(tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
			r = 1;
		i++;
	}
	free(tmp);
	return (r);
}

int	check_all_num(char **c_f, int n)
{
	int i;

	i = 0;
	if (!c_f)
		return (1);
	while (c_f[i])
	{
		if (check_n(c_f[i]) == 1)
			return(1);
		i++;
	}
	if (i != n)
		return (1);
	return (0);
}

int	check_p(char **c_f, int n)
{
	int i;

	i = 0;
	if (!c_f)
		return (1);
	while (c_f[i])
		i++;
	if (i != n)
		return (1);
	return (0);
}