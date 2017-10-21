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

static int	ft_is_command(t_process *p)
{
	int i;

	i = 0;
	g_dt.map[0][p->mem_addres] == 0x01 ? i = 1 : 0;
    g_dt.map[0][p->mem_addres] == 0x02 ? i = 2 : 0;
    g_dt.map[0][p->mem_addres] == 0x03 ? i = 3 : 0;
    g_dt.map[0][p->mem_addres] == 0x04 ? i = 4 : 0;
    g_dt.map[0][p->mem_addres] == 0x05 ? i = 5 : 0;
    g_dt.map[0][p->mem_addres] == 0x06 ? i = 6 : 0;
    g_dt.map[0][p->mem_addres] == 0x07 ? i = 7 : 0;
    g_dt.map[0][p->mem_addres] == 0x08 ? i = 8 : 0;
    g_dt.map[0][p->mem_addres] == 0x09 ? i = 9 : 0;
	g_dt.map[0][p->mem_addres] == 0x0A ? i = 10 : 0;
    g_dt.map[0][p->mem_addres] == 0x0B ? i = 11 : 0;
    g_dt.map[0][p->mem_addres] == 0x0C ? i = 12 : 0;
    g_dt.map[0][p->mem_addres] == 0x0D ? i = 13 : 0;
    g_dt.map[0][p->mem_addres] == 0x0E ? i = 14 : 0;
    g_dt.map[0][p->mem_addres] == 0x0F ? i = 15 : 0;
    g_dt.map[0][p->mem_addres] == 0x10 ? i = 16 : 0;
	return (i);
}

void	ft_execute_command(t_process *p, int c)
{
	//c == 1 ? ft_live(p) : 0;
	c == 2 ? ft_ld_lld(p, 'n') : 0;
	c == 3 ? ft_st(p) : 0;
	// c == 4 ? ft_add(p) : 0;
	// c == 5 ? ft_sub(p) : 0;
	// c == 6 ? ft_and(p) : 0;
	// c == 7 ? ft_or(p): 0;
	// c == 8 ? ft_xor(p) : 0;
	c == 9 ? ft_zjump(p) : 0;
	// c == 10 ? ft_ldi(p) : 0;
	c == 11 ? ft_sti(p) : 0;
	// c == 12 ? ft_fork(p) : 0;
	c == 13 ? ft_ld_lld(p, 'l') : 0;
	// c == 14 ? ft_lldi(p) : 0;
	// c == 15 ? ft_lfork(p) : 0;
	// c == 16 ? ft_aff(p) : 0;
}

static void ft_execute_process(t_process *p)//, t_data *data, unsigned char **map)
{
	int i;

	i = 0;//ft_is_command(p);
	if(i != 0)
    {
		p->command = i;
		if (i == 11)//i != 1 && i != 9 && i != 12 && i != 15)
			p->codage_octal =  (int)(g_dt.map[0][ft_increment_index(p)]);
		ft_execute_command(p, i);
    }
    else
	{
		p->mem_addres = ft_increment_index(p);
	}
}

void ft_game_cycle(t_process *process)//, unsigned char **map)
{
	t_process *p;
	
	g_dt.cycle = 0;
	g_dt.change_cycle = 0;
	while (g_dt.cycle2die > 0 || process != NULL) //add if for --dump
	{
		p = process;
		while (p != NULL)
		{
			ft_execute_process(p);//, &g_dt, g_dt.map);
			p = p->next;
			g_dt.cycle++;
			g_dt.change_cycle++;
			print_map();
			ft_putstr_vis_int((int)g_dt.cycle);
		}
		//ft_reset(); //занулять обратно, все что нужно занулять каждый период (например количесство жизней у игроков)
		if (g_dt.change_cycle == g_dt.cycle2die)
		{ //tнастало время цыкла умереть
			ft_change_cycle2die(&g_dt);
			ft_kill_processes(&process);
			g_dt.change_cycle = 0;
		}
	}
	ft_putstr_vis("FINISH\n"); /*вывод победителя и его имя!*/
}
