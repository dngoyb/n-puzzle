/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:47:04 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 09:49:17 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			ft_is_empty(t_queue *q)
{
	return (q->top == NULL);
}

t_queue		init()
{
	t_queue *tmp;
	
	tmp = (t_queue *)malloc(sizeof(t_queue));
    tmp->top = NULL;
    return (*tmp);
}

void		ft_penqueue(t_queue *q, t_node *node, int prty)
{
    t_qnode *new_node = (t_qnode *)malloc(sizeof(t_qnode));
    new_node->node = node;
    new_node->next = NULL;
    new_node->priority = prty;

    if (ft_is_empty(q))
        q->top = new_node;
    else
    {
        t_qnode *temp = q->top;
        if(temp->priority > new_node->priority)
        {
            q->top = new_node;
            new_node->next = temp;
            return ;
        }
        while (temp->next != NULL && temp->next->priority < new_node->priority)
			temp = temp->next;
        if (temp->next != NULL)
			new_node->next = temp->next;
        temp->next = new_node;
    }
}

t_node		*dequeue(t_queue *q)
{
	if (ft_is_empty(q))
		return (NULL);
    t_qnode *temp = q->top;
    t_node *temp_node = q->top->node;
    q->top = q->top->next;
    free(temp);
    return temp_node;
}
