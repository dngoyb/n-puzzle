#include "npuzzle.h"

static void		check_empty_pos(int **matrix, int size, int *x, int *y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (j++ < size)
		{
			if (matrix[i][j] == 0)
			{
				*x = i;
				*y = j;
			}
		}
	}
}

int				**read_file(int *size, char *file, int *ix, int *iy)
{
    char		*temp;
    int			i;
    int			k;
    int			j;
    int			fd;
    int			**ret;
    char 		**spl;

    fd = open(file, O_RDONLY);
    i = 0;
    k = 0;
	ret = NULL;
    if (fd > 0)
    {
        while (get_next_line(fd, &temp))
        {
			if (temp[0] == '#')
				continue ;
            if (i == 0)
            {
                *size = ft_atoi(temp);
                ret = (int **)malloc(sizeof(int *) * (*size));
                for (i = 0; i < *size; i++)
                    ret[i] = malloc(sizeof(int));
                i = 0;
            }
            else
            {
                j = -1;
                spl = ft_strsplit(temp, ' ');
                while (++j < *size)
					ret[k][j] = ft_atoi(spl[j]);
                k++;
            }
            i++;
        }
		check_empty_pos(ret, *size, ix, iy);
	}
	return (ret);
}
