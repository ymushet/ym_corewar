#include "../corewar.h"

static int ft_read_argc(unsigned char *args)
{
	return (1);
}

static int ft_move_live_carrige(t_process *process) //+5;
{
	return (5);
}

void ft_live(t_process *process)
{
	if (process->exec_cycle == 0)
	{
		//g_dt.last_live = //process->number;
		g_dt.nbr_live++;
		process->alive = 1;
		process->exec_cycle = -1;
		process->mem_addres = ft_move_live_carrige(process);
		//g_dt.map[2] = process-> - ???
	}
	else if (process->exec_cycle == -1)
	{
		process->exec_cycle = op_tab[0].cycle;
	}
	else
	{
		process->exec_cycle--;
	}
}
