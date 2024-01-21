/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:54:39 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/21 10:43:53 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int     see_up(int **matrix, int *k)
{       
        int     max;
        int     i;
        int     count;

        count = 1;
        i = 1;
        max = matrix[*k][i];
        while (i < 4)
        {
                if (matrix[i][*k] < matrix[i + 1][*k])
                {
                        max = matrix[i + 1][*k];
                        count++;
                }
                i++;
        }
        return (count);
}       

bool    check_up(int **matrix)
{       
        int     k;
        int     should_see;

        k = 1;
        while (k < 5)
        {
                should_see = matrix[0][k];
                if (see_up(matrix, &k) != should_see)
                        return (false);
                k++;
        }
        return (true);
}    
