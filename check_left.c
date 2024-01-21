/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:50:14 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/21 10:42:59 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int     see_left(int **matrix, int *k)
{       
        int     max;
        int     i;
        int     count;

        count = 1;
        i = 4;
        max = matrix[*k][i];
        while (i > 1)
        {
                if (matrix[*k][i] < matrix[*k][i - 1])
                {
                        max = matrix[*k][i - 1];
                        count++;
                }
                i--;
        }
        return (count);
}       

bool    check_left(int **matrix)
{       
        int     k;
        int     should_see;

        k = 1;
        while (k < 5)
        {
                should_see = matrix[k][5];
                if (see_left(matrix, &k) != should_see)
                        return (false);
                k++;
        }
        return (true);
}     
