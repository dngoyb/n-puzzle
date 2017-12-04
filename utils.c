#include "npuzzle.h"

void        copy_array(int ***dest, int **src, int size)
{
    int **temp;

    temp = (int **)malloc(sizeof(int *) * size);
    for (int i=0; i < size; i++)
		temp = malloc(sizeof(int));

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            temp[y][x] = src[y][x];
        }
    }
    *dest = temp;
}