/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:20:23 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 09:44:30 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int			printMatrix(int **mat, int size)
{
    static int move = 0;

	printf("-----------\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] == 0)
				(j != 0) ? printf("    \x1b[34m_\x1b[0m") : printf("\x1b[34m_\x1b[0m");
            else
                (j != 0) ? printf("%5d", mat[i][j]) : printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    printf("-----------\nMove: %5d\n", move++);
    return (0);
}

void 		printPath(t_node *root, int size)
{
    if (root == NULL)
        return ;
    printPath(root->parent, size);
    printMatrix(root->matrix, size);
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};

int			isSafe(int x, int y, int size)
{
    return (x >= 0 && x < size && y >= 0 && y < size);
}

t_node		*new_item(int **mat, int x, int y, int nx, int ny, int level, t_node *parent, int size)
{
	t_node		*node;

    node = (t_node *)malloc(sizeof(t_node));
    node->parent = parent;
    node->matrix = (int **)malloc(sizeof(int *) * size);

    for (int i=0; i < size; i++)
		node->matrix[i] = malloc(sizeof(int));

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
			node->matrix[y][x] = mat[y][x];
    }
    if (node)
        ft_swap(&(node->matrix[x][y]), &(node->matrix[nx][ny]));
    node->level = level;
    node->x = nx;
    node->y = ny;
    return (node);
}

int     cost_h(int **grid, int **final, int size)
{
    int cost;

   	cost = manhattan(grid, final, size);
    //cost = missplaced(grid, final, size);
    //printf("the cost is %d\n", cost);
    return (cost);
}

int main(int c, char **av)
{
    t_queue queue;
    t_node  *node;
    t_node  *min;
    t_node  *child;
    t_closed    *close = NULL;
    int iter = 0;
    int **final;
    int **initial;
    int size;
    int g_x;
    int g_y;

    initial = read_file(&size, av[1], &g_x, &g_y);
    final = get_goal(size);
    node = new_item(initial, g_x, g_y, g_x, g_y, 0, NULL, size);

    queue = init();
    node->cost = cost_h(initial, final, size);
    pEnqueue(&queue, node, node->cost);

    while (!isEmpty(&queue))
    {
		iter++;
        min = dequeue(&queue);
        if (min->cost == 0)
        {
            printPath(min, size);
		//	printf("iter: %d\n", iter);
            break ;
        }
        push(&close, min->matrix, size);
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i], size))
            {
                child = new_item(min->matrix, min->x,
                                      min->y, min->x + row[i],
                                      min->y + col[i],
                                      min->level + 1, min, size);
                child->cost = cost_h(child->matrix, final, size);

                if (!closed(close, child->matrix, size))
                    pEnqueue(&queue, child, child->cost + min->level);
            }
        }
    }
    return (0);
}
