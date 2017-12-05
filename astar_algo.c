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

void        astar_algo(int **final, t_node *i_node, int size, int type)
{
    t_node  *min;
    t_node  *child;
    t_queue queue;
    t_closed    *close = NULL;
    int row[] = {1, 0, -1, 0};
    int col[] = {0, -1, 0, 1};

    queue = init();
    pEnqueue(&queue, i_node, i_node->cost);
    while (!isEmpty(&queue))
    {
        min = dequeue(&queue);
        if (min->cost == 0)
        {
            ft_constract_path(min, size);
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
                child->cost = cost_h(child->matrix, final, size, type);
                if (!closed(close, child->matrix, size))
                    pEnqueue(&queue, child, child->cost + min->level);
            }
        }
    }
}