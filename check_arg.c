/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:40:08 by tle-moel          #+#    #+#             */
/*   Updated: 2024/01/20 14:24:59 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool    check_arg(char *str)
{
        int     i;
        int     count;

        i = 0;
        count = 0;
        while (str[i] != '\0')
        {
                if (str[i] >= '1' && str[i] <= '4')
                {
                        count++;
                        i++;
                	if (str[i] == ' ' && str[i + 1] == '\0')
			{
                        	return (false);
			}
			else if (str[i] == ' ')
			{
				i++;
			}
			else if (str[i] == '\0')
			{
				break ;
			}
                	else
                        	return (false);
		}
		else
			return (false);
        }
        if (count != 16)
                return (false);
        else
                return (true);
}

