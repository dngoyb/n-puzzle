/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:45:30 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 09:51:37 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

typedef struct      s_node
{
    int             **matrix;
    int             x;
    int             y;
    int             cost;
    int             level;
    struct s_node   *parent;
}                   t_node;

typedef struct      s_qnode
{
    int             priority;
    t_node          *node;
    struct s_qnode  *next;
}                   t_qnode;

typedef struct      s_queue
{
    t_qnode         *top;
}                   t_queue;

typedef struct      s_closed
{
    int             **matrix;
    struct s_closed *next;
}                   t_closed;

typedef struct      s_puzzle
{
    t_queue         *queue;
    t_queue         *queue1;
    t_node          *child;
    t_node          *child1;
    int             g_x;
    int             g_y;
    int             size;
}                   t_puzzle;

t_queue             init();
int                 isEmpty(t_queue *q);
void                pEnqueue(t_queue *q, t_node *node, int prty);
t_node              *dequeue(t_queue *q);
int                 manhattan(int **grid, int **final, int size);
int                 missplaced(int **initial, int **final, int size);

int                 compare_grids(int **a, int **b, int size);

void                push(t_closed **head, int **matrix, int size);
int                 closed(t_closed *head, int **grid, int size);
int                 **read_file(int *size, char *file, int *ix, int *iy);

int                 **get_goal(int n);
void                copy_array(int ***dest, int **src, int size);
int                 ft_solvable(int **matrix, int size);

#endif
