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

int			isEmpty(t_queue *q)
{
	return (q->top == NULL);
}

t_queue		init()
{
	t_queue *tmp;
	
	tmp = malloc(sizeof(t_queue));
    tmp->top = NULL;
    return (*tmp);
}

void		pEnqueue(t_queue *q, t_node *node, int prty)
{
    t_qnode *newNode = malloc(sizeof(t_qnode));
    newNode->node = node;
    newNode->next = NULL;
    newNode->priority = prty;

    if (isEmpty(q))
        q->top = newNode;
    else
    {
        t_qnode *temp = q->top;
        if(temp->priority > newNode->priority)
        {
            q->top = newNode;
            newNode->next = temp;
            return ;
        }
        while (temp->next != NULL && temp->next->priority < newNode->priority)
			temp = temp->next;
        if (temp->next != NULL)
			newNode->next = temp->next;
        temp->next = newNode;
    }
}

t_node		*dequeue(t_queue *q)
{
	if (isEmpty(q))
		return (NULL);
    t_qnode *temp = q->top;
    t_node *tempNum = q->top->node;
    q->top = q->top->next;
    free(temp);
    return tempNum;
}
