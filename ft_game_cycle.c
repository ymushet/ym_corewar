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

static void ft_execute_process(t_process *p)//, t_data *data, unsigned char **map)
{
	if((unsigned int)g_dt.map[0][p->mem_addres] == 0x01)
    {
		printf("1\n");
        //while (1);
    }
    else
    {
        printf("2\n");
		//while (1);
    }
}

void ft_game_cycle(t_process *process)//, unsigned char **map)
{
	t_process *p;
	
	while (g_dt.cycle2die > 0 || process != NULL) //add if for --dump
	{
		p = process;
		while (p != NULL)
		{
			//ft_execute_process(g_dt.process_g);//, &g_dt, g_dt.map);
			p = p->next;
			g_dt.cycle++;
		}
		//print_map(data);
		ft_change_cycle2die(&g_dt);
		ft_kill_processes(&process);
	}
	printf("FINISHED\n");
}
