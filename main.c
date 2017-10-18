#include "corewar.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Wrong corewar arguments\n");
	else
	{
		ft_init_global();
		// ft_parse_argc(argc, argv);
		g_dt.map = ft_create_map(g_dt.player_g, g_dt.count_players);
		g_dt.process_g = ft_create_proceses(g_dt.player_g);
		ft_game_cycle(g_dt.process_g, g_dt.map);
	}
	return (0);
}
