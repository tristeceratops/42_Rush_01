/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:39:00 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/21 10:43:42 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	see_right(int **matrix, int *k)
{
	int	max;
	int	i;
	int	count;

	count = 1;
	i = 1;
	max = matrix[*k][i];
	while (i < 4)
	{
		if (matrix[*k][i] < matrix[*k][i + 1])
		{
			max = matrix[*k][i + 1];
			count++;
		}
		i++;
	}
	return (count);
}

bool	check_right(int **matrix)
{
	int	k;
	int	should_see;
	
	k = 1;
	while (k < 5)
	{
		should_see = matrix[k][0];
		if (see_right(matrix, &k) != should_see)
			return (false);
		k++;
	}
	return (true);
}
