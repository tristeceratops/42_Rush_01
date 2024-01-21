/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:21:56 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/21 10:57:24 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	find_empty_cell(int **matrix, int *row, int *column)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			if (matrix[i][j] == 0)
			{
				*row = i;
				*column = j;
				return (true);
			}
			else
				j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid(int **matrix, int row, int column, int guess)
{
	int	i;
	
	i = 1;
	while (i < 5)
	{
		if (matrix[row][i] == guess)
			return (false);
		if (matrix[i][column] == guess)
			return (false);
		i++;
	}
	return (true);
}

bool	solve(int **matrix)
{
	int row;
	int column;
	int guess;
	
	if (find_empty_cell(matrix, &row, &column) == false)
		return (true);
	guess = 1;
	while (guess < 5)
	{
		if (is_valid(matrix, row, column, guess) == true)
		{
			matrix[row][column] = guess;
			if (solve(matrix) == true)
				return (true);
			matrix[row][column] = 0;
		}
		guess++;
	}
	return (false);
}
