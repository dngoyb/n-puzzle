/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:49:23 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 09:51:15 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		push(t_closed **head, int **matrix, int size)
{
	t_closed *new_node;

    new_node = (t_closed *)malloc(sizeof(t_closed));
    new_node->matrix = (int **)malloc(sizeof(int *) * size);
    for (int i=0; i < size; i++)
        new_node->matrix[i] = (int *)malloc(sizeof(int));
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
            new_node->matrix[y][x] = matrix[y][x];
    }
    new_node->next = *head;
    *head = new_node;
}

int			compare_grids(int **a, int **b, int size)
{
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
            if (a[y][x] != b[y][x])
                return (0);
    return (1);
}

int			closed(t_closed *head, int **grid, int size)
{
	t_closed *current = head;

    while (current != NULL)
    {
        if (compare_grids(grid, current->matrix, size) == 1)
            return (1);
        current = current->next;
    }
    return (0);
}
