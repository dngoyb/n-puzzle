#include "npuzzle.h"

int 	**get_goal(int n)
{
	int i,j,k=1;
	int	ab = n *n;

	int l=0,r=1,d=0,u=0;
	int **a;

	a = (int **)malloc(sizeof(int *) * n);
	for (i=0; i < n; i++)
		a[i] = malloc(sizeof(int));

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	i=0;
	j=-1;
	while(k<=(n*n))
	{
		if(r==1)
		{
			j++;
			if(j==n || a[i][j]!=0)
			{
				r=0;
				d=1;
				j--;
			}
			else
			{
				a[i][j]= (k == ab) ? 0 : k;
				k++;
			}
		}
		else if(d==1)
		{
			i++;
			if(i==n || a[i][j]!=0)
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
		else if(l==1)
		{
			j--;
			if(j<0 || a[i][j]!=0)
			{
				l=0;
				j++;
				u=1;
			}
			else
			{
				a[i][j]= (k == ab) ? 0 : k;
				k++;
			}

		}
		else if(u==1)
		{
			i--;
			if(i<0 || a[i][j]!=0)
			{
				i++;
				u=0;
				r=1;
			}
			else
			{
				a[i][j]= (k == ab) ? 0 : k;
				k++;
			}
		}
	}
	return (a);
}
