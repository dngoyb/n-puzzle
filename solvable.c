/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:03:28 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 10:22:27 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	ft_inversions(int *matrix, int size)
{
	int inv_count;
	
	inv_count = 0;
	for (int i = 0; i < (size * size) - 1; i++)
		for (int j = i + 1; j < (size * size); j++)
			if (matrix[j] && matrix[i] && matrix[i] > matrix[j])
				inv_count++;
	return (inv_count);
}

int			ft_solvable(int **matrix, int size)
{
    int     count;
    int     i;
    int     j;
    int     *new_mat;

    new_mat = (int *)malloc(sizeof(int) * (size * size));
    i = -1;
    count = 0;
    while (++i < (size))
    {
        j = -1;
        while (++j < size)
            new_mat[count++] = matrix[i][j];
    }
	count = ft_inversions(new_mat, size);
	return ((count % 2 == 0) ? 0 : 1);
}