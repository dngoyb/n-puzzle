/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:01:58 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 13:02:12 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

/*
** I have to generate a random puzzle that will be ran in case a puzzle file is missing
*/

int        **random_puzzle(int *size, int *ix, int *iy)
{
    int     **puzzle;
    int     times;
    int     i = 0;

    (void)size;
    puzzle = get_goal(3);
    srand((unsigned)time(NULL));
    times = 100 + rand() % 100;
    while (i < times)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                srand((unsigned)time(0) * i * j);
                ft_swap(&(puzzle[i][j]), &(puzzle[rand() % (i + 1)][rand() % (j + 1)]));
            }
        }
        i++;
        if (!(i < times) && !ft_solvable(puzzle, 3))
            times++;
    }
    check_empty_pos(puzzle, 3, ix, iy);
    return (puzzle);
}