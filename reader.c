#include "npuzzle.h"

int        **read_file(int *size, char *file, int *ix, int *iy)
{
    char *temp;
    int  i;
    int k;
    int   j;
    int  fd;
    int  **ret;
    char    **spl;

    fd = open(file, O_RDONLY);
    i = 0;
    k = 0;
    if (fd)
    {
        while (get_next_line(fd, &temp))
        {
			if (temp[0] == '#')
				continue ;
            if (i == 0)
            {
                *size = atoi(temp);
                ret = (int **)malloc(sizeof(int *) * (*size));
                for (i = 0; i < *size; i++)
                    ret[i] = malloc(sizeof(int));
                i = 0;
            }
            else
            {
                j = 0;
                spl = ft_strsplit(temp, ' ');
                while (j < *size)
                {
                    ret[k][j] = atoi(spl[j]);
                    j++;
                }
                k++;
            }
            i++;
        }
    }
    for (int y = 0; y < *size; y++)
    {
        for (int x = 0; x < *size; x++)
        {
            if (ret[x][y] == 0)
            {
                *ix = x;
                *iy = y;
            }
        }
    }
    return (ret);
}
