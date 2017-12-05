#include "npuzzle.h"

static int		moves(int xp, int yp, int value, int **grid, int size)
{
    int xm = 0;
    int ym = 0;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (grid[x][y] == value)
            {
                xm = (x != xp) ? x - xp : 0;
                ym = (y != xp) ? y - yp : 0;
                return ((abs(xm) + abs(ym)));
            }
        }
    }
    return (0);
}

int		manhattan(int **grid, int **final, int size)
{
    int comp = 0;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (final[x][y] != grid[x][y])
            {
                comp += moves(x, y, final[x][y], grid, size);
            }
        }
    }
    return (comp);
}

int		linearconflict(int **grid, int **final, int size)
{
    (void)grid;
    (void)final;
    (void)size;
    printf("Requested a non existing heurastics\n");
    return (0);
}

int     missplaced(int **initial, int **final, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}
