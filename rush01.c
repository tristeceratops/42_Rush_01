/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:58:09 by ewoillar          #+#    #+#             */
/*   Updated: 2024/01/20 13:13:27 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include        <stdio.h>
#include        <stdlib.h>

void    rush01(void)
{
        //int   check_err;
        int     nb_ligne;
        int     nb_colonne;
        char    **table;
        int     i;
        int     j;

        nb_ligne = 5;
        nb_colonne = 5;
        i = 0;
        /*
        check_err = error_str_check(str, 4);
        if(check_err)
        {
                //err
        }*/
        table = malloc(nb_ligne* sizeof(char*));
        while(i < nb_ligne)
        {
                table[i] = malloc(nb_colonne* sizeof(char));
                i++;
        }
        i = -1;
        while(i++ < nb_ligne-1)
        {
                j = -1;
                while(j++ < nb_colonne-1)
                {
                        table[i][j] = '1';
                        printf("%c ", table[i][j]);
                }
                printf("\n");
        }
        i = -1;
        while (i++ <nb_ligne - 1)
        {
                free(table[i]);
        }
        free(table);
}
