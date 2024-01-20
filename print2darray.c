/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2darray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadeq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:30:27 by asadeq            #+#    #+#             */
/*   Updated: 2024/01/20 14:14:12 by asadeq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4

void	write_int(int num)
{
	char	digit;

	digit = num + '0';
	write(1, &digit, 1);
}

void	print_2d_array(int array[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			write_int(array[i][j]);
			if (j < (SIZE - 1))
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
