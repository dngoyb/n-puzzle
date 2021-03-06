/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:33:59 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/22 14:08:46 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int		moves(int xp, int yp, int value, int **grid, int size)
{
    int xm = 0;
    int ym = 0;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (grid[x][y] == value)
            {
                xm = (x != xp) ? x - xp : 0;
                ym = (y != xp) ? y - yp : 0;
                return ((abs(xm) + abs(ym)));
            }
        }
    }
    return (0);
}

int		manhattan(int **grid, int **final, int size)
{
    int comp = 0;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (final[x][y] != grid[x][y])
            {
                comp += moves(x, y, final[x][y], grid, size);
            }
        }
    }
    return (comp);
}

int     missplaced(int **initial, int **final, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}
