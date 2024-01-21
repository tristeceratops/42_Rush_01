/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:56:45 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/21 11:00:48 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int     see_down(int **matrix, int *k)
{       
        int     max;
        int     i;
        int     count;

        count = 1;
        i = 4;
        max = matrix[*k][i];
        while (i > 1)
        {
                if (matrix[i][*k] < matrix[i - 1][*k])
                {
                        max = matrix[i - 1][*k];
                        count++;
                }
                i--;
        }
        return (count);
}

bool    check_down(int **matrix)
{
        int     k;
        int     should_see;

        k = 1;
        while (k < 5)
        {
                should_see = matrix[5][k];
                if (see_down(matrix, &k) != should_see)
                        return (false);
                k++;
        }
        return (true);
}
