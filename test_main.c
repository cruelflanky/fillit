#include "fillit.h"
#include <stdio.h>

char **create_map(int i)
{
    char **map;
    char **str;
    int x;

    x = 0;
    map = (char **)malloc(sizeof(char *) * i);
    str = map;
    while (x < i)
    {
        *map = (char *)malloc(sizeof(char) * i);
        ft_bzero(*map, i);
        x++;
        map++;
    }
    return (str);
}

int     main(void)
{
    char **map;
    int i = 4;

    map = create_map(i);
    while (i--)
    {
        printf("%s\n", *map);
        map++;
    }
    return (0);
}