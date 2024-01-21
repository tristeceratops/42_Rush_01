/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:44:35 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/21 11:16:33 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


bool	check_arg(char *str);
int	**create_grid(char *str);
bool	solve(int **matrix);
bool	check_left(int **matrix);
bool	check_right(int **matrix);
bool	check_up(int **matrix);
bool	check_down(int **matrix);

bool	check_skyscraper(int **matrix)
{
	if (!check_left(matrix))
		return (false);
	if (!check_right(matrix))
		return (false);
	if (!check_up(matrix))
		return (false);
	if (!check_down(matrix))
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	char	*grid_str;
	int	**grid;
	int	rows;
	int	cols;

	rows = 6;
	cols = 6;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid_str = argv[1];
	if (!check_arg(grid_str))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid = create_grid(grid_str);
	
	if (solve(grid) == true)
	{
		if (check_skyscraper(grid) == true)
		{
			write(1, "Yes\n", 4);
			for (int i = 0; i < rows; i++)
        		{
                		for (int j = 0; j < cols; j++)
                		{
                        		printf("%d ", grid[i][j]);
                		}
                		printf("\n");
        		}
			break ;
		}
	}
	if (solve(grid) == false)
		write(1, "No solution\n", 12);
	
	for (int i = 0; i < rows; i++) 
	{
		free(grid[i]);
	}
	free(grid);

	return (0);
}
