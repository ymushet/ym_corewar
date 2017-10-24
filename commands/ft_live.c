#include "../corewar.h"

static int ft_increment_live(int current, int i)
{
	if (current + i >= MEM_SIZE)
	{
		return ((current + i) - MEM_SIZE);
	}
	else if (current + i < MEM_SIZE)
		return (current + i);
}

static int ft_get_nbr(t_process *p)
{
	int j;
	unsigned char str[4];

	ft_bzero(str, 4);
	str[0] = g_dt.map[0][ft_increment_index(p)];
	str[1] = g_dt.map[0][ft_increment_live(p->mem_addres + 1)];
	str[2] = g_dt.map[0][ft_increment_live(p->mem_addres + 2)];
	str[3] = g_dt.map[0][ft_increment_live(p->mem_addres + 3)];
	j = ft_create_int(str);
	return (j);
}

static t_player *ft_is_live_arg_valid(t_process *process)
{
	t_player *player;
    int nbr;

	player = g_dt.player_g;
	nbr = ft_get_nbr(process);
	nbr = nbr * -1;
	if (player != NULL)
	{
		if (player->number == -nbr)
			return(player);
		player = player->next;
	}
	return (NULL);
}

void ft_live(t_process *process)
{
	t_player *player;

	if (process->exec_cycle == 0)
	{
		if((player = ft_is_live_arg_valid(process)) != NULL)
		{
			g_dt.last_live = player->number;
			player->n_live++;
		}
		process->alive = 1;
		process->exec_cycle = -1;
		process->mem_addres = ft_increment_live(process->mem_addres, 4);
		g_dt.nbr_live++;
	}
	else if (process->exec_cycle == -1)
	{
		process->exec_cycle = g_tab[0].cycle;
	}
	else
	{
		process->exec_cycle--;
	}
}
