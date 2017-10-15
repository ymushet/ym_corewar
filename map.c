#include "corewar_vm_validation.h"

void    ft_copy_com(char **map, t_player *player, int i)
{
	int    len;
	int    j;
	
	j = 0;
	len = ft_strlen(player->instructions);
	while (j < len)
	{
		map[0][i + j] = player->instructions[j];
		map[1][i + j] = player->number + 64;
		i++;
		j++;
	}
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
	map[3] = NULL;
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

