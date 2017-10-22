#include "corewar.h"

static void ft_change_cycle2die(t_data *data)
{
	if (data->nbr_live >= NBR_LIVE)
	{
		data->cycle2die -= CYCLE_DELTA;
		data->nbr_live = 0;
	}
	else
	{
		if (data->max_checks == MAX_CHECKS)
		{
			data->cycle2die -= CYCLE_DELTA;
			data->max_checks = 0;
		}
		else
		{
			data->max_checks++;
		}
	}
}

/*
*
* если функции нет
* * посмотреть функция ли это, если нет то коретку передвинуть на одну
* * если есть сохранить функцию, сохранить стоимость
* если у нас есть функция
* * осталась ли стоимость, нет - вызываем функцию(указатель на функцию затираем), да - уменьшаем стоимость
*/

static void	ft_execute_command(t_process *p)
{
	int command;

	if (p->f == NULL)
	{
		command = (int)g_dt.map[0][p->mem_addres] - 1;
		if (command > 0 && command < 17)
		{
			p->f = g_f[command - 1];
			p->exec_cycle = g_tab[command - 1].cycle;
		}
		else
			p->mem_addres = (p->mem_addres + 1) % MEM_SIZE;
	}
	else
	{
		if (p->exec_cycle == 0)
		{
			p->f(p);
			p->f = NULL;
		}
		else
			p->exec_cycle--;
	}
}

void ft_game_cycle(t_process *process)
{
	t_process *p;
	
	g_dt.cycle = 0;
	g_dt.change_cycle = 0;
	while (g_dt.cycle2die > 0 || process != NULL)
	{
		p = process;
		while (p != NULL)
		{
			ft_execute_command(p);
			p = p->next;
			g_dt.cycle++;
			g_dt.change_cycle++;
			print_map();
		}
		if (g_dt.change_cycle == g_dt.cycle2die)
		{
			ft_change_cycle2die(&g_dt);
			ft_kill_processes(&process);
			g_dt.change_cycle = 0;
		}
	}
	ft_putstr_vis("FINISH\n");
}
