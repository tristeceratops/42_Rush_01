/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:43:08 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/20 16:30:02 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     putdigit(char c)
{
        int     nb;

        nb = c - '0';
        return (nb);
}

int     *exercise_value(char *str)
{
        int     *values;
        int     i;
        int     j;

        i = 0;
        j = 0;
        values = malloc(sizeof(int) * 16);
        while (i < 16)
        {
                values[i] = putdigit(str[j]);
                i++;
                j += 2;
        }
        return (values);
}


int     **create_empy_grid(int rows, int cols)
{
        int **grid;
        int     i;
        int     j;
        int     k;

        grid = malloc(sizeof(int *) * rows);
        i = 0;
        while (i < rows)
        {
                grid[i] = malloc(sizeof(int) * cols);
                i++;
        }
        i = 0;
        k = 0;
        while (i < rows)
        {
                j = 0;
                while (j < cols)
                {
                        grid[i][j] = 0;
			j++;
                }
		i++;
        }
        return (grid);
}

int     **populate_grid(int **empty_grid, int *values)
{
        int     i;
        int     k;

        i = 1;
        k = 0;
	while (k < 16)
	{
		if (k < 4)
			empty_grid[0][i] = values[k];
		else if (k < 8)
			empty_grid[5][i] = values[k];
		else if (k < 12)
			empty_grid[i][0] = values[k];
		else
			empty_grid[i][5] = values[k];
		k++;
		i++;
		if (i == 5)
			i = 1;
	}
        return (empty_grid);
}

int	**create_grid(char *str)
{
	int	*values;
	int	**grid;
	int	rows;
	int	cols;
	
	rows = 6;
	cols = 6;
	values = exercise_value(str);
	grid = create_empy_grid(rows, cols);
	grid = populate_grid(grid, values);

	free(values);

	return (grid);
}
