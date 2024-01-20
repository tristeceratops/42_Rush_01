/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:27:42 by ewoillar          #+#    #+#             */
/*   Updated: 2024/01/20 16:36:42 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ROWS 6
#define COLS 6

int     check_taille_tour(int tableau [ROWS][COLS], int size, int x, int y)
{
        int     indicator_rule;
        int     max_size_mem;
        int     iteration_answer;
        int     iteration;
        int     x_case;
        int     y_case;
        int     ret_value;

        indicator_rule = tableau[x][0];
        iteration_answer = 1;
        iteration = 1;
        x_case = x;
        y_case = 1;
        max_size_mem = tableau[x_case][y_case];
        ret_value = 0;
        while(iteration < size - 1)
        {
                y_case++;
                if(tableau[x_case][y_case] > max_size_mem)
                {
                        max_size_mem = tableau[x_case][y_case];
                        iteration_answer++;
                }
                iteration++;
        }
        if(indicator_rule != iteration_answer)
        {
                ret_value = - 1;
        }
        return ret_value;
}

int     check_table(int tableau[ROWS][COLS], int size, int x, int y)
{
        int             c;
        int             i;
        int             j;
        int             stoploop;
        int             ret;

        c = tableau[x][y];
        i = 1;
        j = 1;
        stoploop = 0;
        ret = 0;
        //ligne
        while(i != size - 1 && !stoploop)
        {
                if(i == x)
                {
                        i++;
                }
                if(tableau[i][y] == c)
                {
                        stoploop = 1;
                        ret = -1;
                }
                i++;
        }
        //colonne
        while(j != size - 1 && !stoploop)
        {
                if(j == y)
                {
                        j++;
                }
                if(tableau[x][j] == c)
                {
                        stoploop = 1;
                        ret = -1;
                }
                j++;
        }
        return  (ret);
}

int     main(void)
{
        int matrix[ROWS][COLS] = {
                        {0, 4, 3, 2, 1, 0},
                        {4, 2, 2, 3, 4, 1},
                        {3, 2, 3, 4, 1, 2},
                        {2, 3, 4, 1, 2, 2},
                        {1, 4, 1, 2, 3, 2},
                        {0, 1, 2, 2, 2, 0}};
        printf("%d",check_table(matrix, 6, 1, 1));
}
    
