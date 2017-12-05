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

    (void)size;
    puzzle = get_goal(3);
    check_empty_pos(puzzle, 3, ix, iy);
    return (puzzle);
}