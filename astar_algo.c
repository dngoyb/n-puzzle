/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:40:00 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 10:40:10 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

/*
** Takes final(goal) state and a node to first state, then adds it to the queue
** then take the top element in the queue and then create childrens for each node
** add all the nodes with a low cost on top of the queue, do this until you reach
** a node with 0 cost(solved state)... Add all evaluated nodes to closed set
** during the process to avoid visiting same node twice...
*/

void        astar_algo(int **final, t_node *i_node, int size, int type)
{
    t_node  *min;
    t_node  *child;
    t_queue queue;
    clock_t start;
    double  spent;
    int     opens;
    int     memory;

    start = clock();
    t_closed    *close = NULL;
    int row[] = {1, 0, -1, 0};
    int col[] = {0, -1, 0, 1};

    queue = init();
    opens = 1;
    memory = 1;
    ft_penqueue(&queue, i_node, i_node->cost);
    while (!ft_is_empty(&queue))
    {
        min = dequeue(&queue);
        if (min->cost == 0)
        {
            ft_constract_path(min, size);
            clock_t fuck = clock();
            spent = (double)(fuck - start) / CLOCKS_PER_SEC;
            printf("-----------\nTime spent : %f s\nTime complexity: %d\nSize complexity: %d\n", spent, opens, memory);
            break ;
        }
        push(&close, min->matrix, size);
        for (int i = 0; i < 4; i++)
        {
            if (ft_issafe(min->x + row[i], min->y + col[i], size))
            {
                child = new_item(min->matrix, min->x,
                                      min->y, min->x + row[i],
                                      min->y + col[i],
                                      min->level + 1, min, size);
                child->cost = cost_h(child->matrix, final, type, size);
                if (!closed(close, child->matrix, size))
                {
                    ft_penqueue(&queue, child, child->cost + min->level);
                    memory++;
                }
            }
        }
        opens++;
    }
}