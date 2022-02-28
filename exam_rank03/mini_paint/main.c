#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	char	c;
}				t_map;

typedef struct s_op
{
	char	type;
	float	x;
	float	y;
	float	rad;
	char	c;
}				t_op;

void	get_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->map = malloc(sizeof(char*) * map->height);
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(char) * map->width);
		while (j < map->width)
		{
			map->map[i][j] = map->c;
//			printf("%c", map->map[i][j]);
			j++;
		}
//		printf("\n");
		j = 0;
		i++;
	}
}

void	draw_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.height)
	{
		while (j < map.width)
		{
			printf("%c", map.map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	draw_full(t_map *map, t_op op)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (sqrt((op.x - j) * (op.x - j) + (op.y - i) * (op.y - i)) < op.rad)
				map->map[i][j] = op.c;
			j++;
		}
		j = 0;
		i++;
	}	
}

int main(int ac, char **av)
{
	t_map	map;
//	t_op	op;
	FILE	*file;
	int		res;

	if (ac != 2)
		return (1);
	file = fopen(av[1], "r");
	res = fscanf(file, "%d %d %c\n", &map.width, &map.height, &map.c);
	printf("%d %d %c\n", map.width, map.height, map.c);
	get_map(&map);
//	draw_map(map);
	map.map[0][2] = 'A';
	draw_map(map);
	(void)res;
/*	while (res != -1 && res != EOF)
	{
		res = fscanf(file, "%c %f %f %f %c\n", &op.type, &op.x, &op.y, &op.rad, &op.c);
		if (res == 5)
			draw_full(&map, op);
	}
	printf("%c %f %f %f %c\n", op.type, op.x, op.y, op.rad, op.c);
	printf("res = %d\n", res);*/
//	get_map(&map);
//	draw_map(map);
	return (0);
}
