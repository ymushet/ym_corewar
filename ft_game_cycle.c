#include "corewar.h"

static void ft_change_cycle2die(t_data *data)
{
	t_player *p;

	p = g_dt.player_g;
	if (g_dt.nbr_live >= NBR_LIVE)
	{
		g_dt.cycle2die -= CYCLE_DELTA;
		g_dt.nbr_live = 0;
	}
	else
	{
		if (g_dt.max_checks == MAX_CHECKS)
		{
			g_dt.cycle2die -= CYCLE_DELTA;
			g_dt.max_checks = 0;
		}
		else
		{
			g_dt.max_checks++;
		}
	}
	while(p)
	{
		p->n_live = 0;
		p = p->next;
	}
}

static void	ft_execute_command(t_process *p)
{
	int command;

	if (p->f == NULL)
	{
		command = (int)g_dt.map[0][p->mem_addres] - 1;
		if (command >= 0 && command < 16)
		{

			p->f = g_f[command];
			p->exec_cycle = g_tab[command].cycle - 1;
		}
		else
			p->mem_addres = (p->mem_addres + 1) % MEM_SIZE;
	}
	else
	{
		p->exec_cycle--;
		if (p->exec_cycle == 0)
		{
//			ft_putstr("mem add: ");
//			ft_putnbr(p->mem_addres);//////////////////////
//			ft_putstr("\n");
//			ft_putstr("regs[0]: ");
//			ft_putnbr(p->regs[0]);//////////////////////
//			ft_putstr("\n");
//			printf("point: %p\n", &p);
			// ft_putnbr(command);
			// ft_putstr("\n");
			//printf("=========com is %s\n", g_tab[command].name);
			p->f(p);
			p->f = NULL;
		}
	}
}

void ft_game_cycle(void)
{
	t_process *p;
	
	g_dt.cycle = 0;
	g_dt.change_cycle = 1;
	while (g_dt.cycle2die > 0 && g_dt.process_g != NULL && g_dt.cycle != g_dt.dump)
	{
		ft_putstr_vis_int(g_dt.cycle);
		p = g_dt.process_g;
		while (p != NULL)
		{
			ft_execute_command(p);
			p = p->next;
		}
		g_dt.cycle++;
		g_dt.change_cycle++;
		if (g_dt.visual == 1)
			print_map();
//		printf("change_cycle %d\n", g_dt.change_cycle);
		if (g_dt.change_cycle == g_dt.cycle2die)
		{
			ft_change_cycle2die(&g_dt);
			ft_kill_processes();
			g_dt.change_cycle = 1;
		}
	}
	if (g_dt.visual == 1)
		final();
}
