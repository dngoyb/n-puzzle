/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:51:41 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/05 09:19:27 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	**alloc(int n)
{
	int		i;
	int		j;
	int		**mem;

	mem = (int **)malloc(sizeof(int *) * n);
	i = -1;
	while (++i < n)
		mem[i] = (int *)malloc(sizeof(int));
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			mem[i][j] = 0;
	}
	return (mem);
}

int			**get_goal(int n)
{
	int i, j, k = 1;
	int	ab = n *n;

	int l = 0, r = 1, d = 0, u = 0;
	int **a;

	a = alloc(n);
	i = 0;
	j = -1;
	while (k <= (n * n))
	{
		if (r == 1)
		{
			j++;
			if (j==n || a[i][j] != 0)
			{
				r=0;
				d=1;
				j--;
			}
			else
			{
				a[i][j] = (k == ab) ? 0 : k;
				k++;
			}
		}
		else if (d == 1)
		{
			i++;
			if (i== n || a[i][j] != 0)
			{
				i--;
				d=0;
				l=1;
			}
			else
			{
				a[i][j] = (k == ab) ? 0 : k;
				k++;
			}
		}
		else if (l == 1)
		{
			j--;
			if (j < 0 || a[i][j] != 0)
			{
				l=0;
				j++;
				u=1;
			}
			else
			{
				a[i][j] = (k == ab) ? 0 : k;
				k++;
			}

		}
		else if (u == 1)
		{
			i--;
			if (i < 0 || a[i][j] != 0)
			{
				i++;
				u = 0;
				r = 1;
			}
			else
			{
				a[i][j] = (k == ab) ? 0 : k;
				k++;
			}
		}
	}
	return (a);
}
