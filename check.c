/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:07:47 by ewoillar          #+#    #+#             */
/*   Updated: 2024/01/20 18:54:36 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ROWS 6
#define COLS 6

typedef struct t_coord
{
	int	x;
	int	y;
}Coord;

int	check_column(int tab[ROWS][COLS], int size, Coord coord)
{
	int	c;
	int	i;
	int	res;

	c = tab[coord.x][coord.y];
	i = 1;
	res = 0;
	while (i < size -1)
	{
		if (i == coord.y)
		{
			i++;
		}
		if (tab[i][coord.y] == c)
		{
			res = -1;
		}
		i++;
	}
	return (res);
}

int	check_row(int tab[ROWS][COLS], int size, Coord coord)
{
	int	c;
	int	i;
	int	res;

	c = tab[coord.x][coord.y];
	i = 1;
	res = 0;
	while (i < size -1)
	{
		if (i == coord.x)
		{
			i++;
		}
		if (tab[coord.x][i] == c)
		{
			res = -1;
		}
		i++;
	}
	return (res);
}

int	check_rule_top(int tab[ROWS][COLS], int size, Coord coord)
{
	Coord	current_coord;
	int		max_mem;
	int		i_a;
	int		res;

	current_coord = (Coord){1, coord.y};
	i_a = 1;
	res = 0;
	max_mem = tab[current_coord.x][current_coord.y];
	while (current_coord.x < size - 1)
	{
		current_coord.x++;
		if (tab[current_coord.x][current_coord.y] > max_mem)
		{
			max_mem = tab[current_coord.x][current_coord.y];
			i_a++;
		}
	}
	if (tab[0][coord.y] != i_a)
	{
		res = -1;
	}
	return (res);
}

int	check_rule_bottom(int tab[ROWS][COLS], int size, Coord coord)
{
	Coord	current_coord;
	int		max_mem;
	int		i_a;
	int		res;

	current_coord = (Coord){size - 2, coord.y};
	i_a = 1;
	res = 0;
	max_mem = tab[current_coord.x][current_coord.y];
	while (current_coord.x > 0)
	{
		current_coord.x++;
		if (tab[current_coord.x][current_coord.y] > max_mem)
		{
			max_mem = tab[current_coord.x][current_coord.y];
			i_a++;
		}
	}
	if (tab[0][coord.y] != i_a)
	{
		res = -1;
	}
	return (res);
}

int	check_rule(int tab[ROWS][COLS], int size, Coord coord)
{
	int	res;

	res = check_rule_top(tab, size, coord);
	if (res >= 0)
	{
		res = check_rule_right(tab, size, coord);
	}
	if (res >= 0)
	{
		res = check_rule_bottom(tab, size, coord);
	}
	if (res >= 0)
	{
		res = check_rule_left(tab, size, coord);
	}
	return (res);
}

int	check_value(int tab[ROWS][COLS], int size, Coord coord)
{
	int	res;

	res = check_row(tab, size, coord);
	if (res >= 0)
	{
		res = check_column(tab, size, coord);
	}
	if (res >= 0)
	{
		res = check_rule(tab, size, coord);
	}
	return (res);
}

int	main(void)
{
	Coord coord;
	coord.x = 1;
	coord.y = 1;
	int	matrix[ROWS][COLS] = 
	{
		{0, 4, 3, 2, 1, 0},
		{4, 2, 2, 3, 4, 1},
		{3, 2, 3, 4, 1, 2},
		{2, 3, 4, 1, 2, 2},
		{1, 4, 1, 2, 3, 2},
		{0, 1, 2, 2, 2, 0}};
	printf("%d", check_value(matrix, 6, coord));
}
