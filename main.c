#include "corewar.h"

void		ft_init_f(void)
{
	g_f[0] = &ft_live;
	g_f[1] = &ft_ld; //works
	g_f[2] = &ft_st; //works
	g_f[3] = &ft_add;
	g_f[4] = &ft_sub;
	g_f[5] = &ft_xor_and_or;
	g_f[6] = &ft_xor_and_or;
	g_f[7] = &ft_xor_and_or;
	g_f[8] = &ft_zjmp;
	g_f[9] = &ft_ldi;
	g_f[10] = &ft_sti;
	g_f[11] = &ft_fork; //works
	g_f[12] = &ft_lld;
	g_f[13] = &ft_lldi;
	g_f[14] = &ft_lfork; //works
	g_f[15] = &ft_aff;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Wrong corewar arguments\n");
	else
	{
		ft_init_global();
		ft_init_f();
		ft_parse_args(0, argv, 1, NULL);
		g_dt.count_processes = g_dt.count_players;
		ft_sort_player();
		g_dt.map = ft_create_map(g_dt.player_g, g_dt.count_players);
		g_dt.process_g = ft_create_proceses(g_dt.player_g);
		init_ncurses();
		print_map();
		ft_game_cycle(g_dt.process_g);
	}
	return (0);
}
