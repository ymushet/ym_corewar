#include "corewar_vm_validation.h"

void    ft_copy_com(char **map, t_player *player, int i)
{
	int    j;
	
	j = 0;
	int k = 0;
	printf("ORIGINAL\n");
	while (k < player->player_size)
	{
		printf("%.2X ", player->instructions[k]);
		k++;
	}
	printf("\n");
	while (j < player->player_size)
	{
		map[0][i + j] = player->instructions[j];
		map[1][i + j] = player->number + 64;
		j++;
	}
	int l = 0;
	printf("COPY\n");
	while (l < player->player_size)
	{
		printf("%.2X ", map[0][l]);
		l++;
	}
	printf("\n");
}

char    **ft_create_map(t_player *player, int n)
{
	int i;
	int mod;
	char **map;
	t_player *p;
	
	i = 0;
	p = player;
	map = malloc(sizeof(char*) * 3);
	map[2] = NULL;
	mod = MEM_SIZE / n;
	map[0] = ft_strnew(MEM_SIZE);
	map[1] = ft_strnew(MEM_SIZE);
	ft_memset(map[1], 48, MEM_SIZE);
	while (p != NULL)
	{
		ft_copy_com(map, p, i * mod);
		p = p->next;
		i++;
	}
	return (map);
}