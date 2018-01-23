/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:47:04 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/23 10:20:00 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		ft_penqueue(t_qnode **q, t_node *node, int prty)
{
    t_qnode *new_node = (t_qnode *)malloc(sizeof(t_qnode));
    new_node->node = node;
    new_node->next = NULL;
    new_node->priority = prty;

    if (!*q)
        *q = new_node;
    else
    {
        t_qnode *temp = *q;
        if(temp->priority > new_node->priority)
        {
            *q = new_node;
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

t_node		*dequeue(t_qnode **q)
{
	if (!*q)
		return (NULL);
    t_qnode *temp = *q;
    t_node *temp_node = (*q)->node;
    *q = (*q)->next;
    free(temp);
    return temp_node;
}
