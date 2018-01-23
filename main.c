/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:20:23 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/23 10:29:40 by ngbanza          ###   ########.fr       */
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

void 		ft_constract_path(t_node *root, int size)
{
    if (root == NULL)
        return ;
    ft_constract_path(root->parent, size);
    printMatrix(root->matrix, size);
}

int			ft_issafe(int x, int y, int size)
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

int     cost_h(int **grid, int **final, int type, int size)
{
    int cost;

    cost = 0;
    if (type <= 0 || type > 2)
           cost = manhattan(grid, final, size) + missplaced(grid, final, size);
    else
    {
        if (type == 1)
            cost = manhattan(grid, final, size);
		else if (type == 2)
			cost = missplaced(grid, final, size);
    }
    return (cost);
}

int main(int c, char **av)
{
    int     **final;
    int     **initial;
    t_node  *node;
    int     size;
    int     g_x;
    int     g_y;
    int     type;
    
    size = 3;
    initial = NULL;
    srand((unsigned)time(NULL));
    if (c >= 2 && c <= 3)
        initial = (c == 2) ? read_file(&size, av[1], &g_x, &g_y) : read_file(&size, av[2], &g_x, &g_y);
    type = (c == 3) ? ft_atoi(ft_strchr(av[1], 'h') + 1) : 0;
    final = get_goal(size);
    initial = (initial) ? initial : random_puzzle(&size, &g_x, &g_y);
    if (!ft_solvable(initial, size))
    {
        printf("Board is not solvable\n");
        exit(1);
    }
    node = new_item(initial, g_x, g_y, g_x, g_y, 0, NULL, size);
    node->cost = cost_h(initial, final, type, size);
    astar_algo(final, node, size, type);
    return (0);
}
