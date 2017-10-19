//
// Created by Maksym Kaliberda on 16.10.17.
//


//
// Created by Maksym Kaliberda on 14.10.17.
//
# include "../corewar.h"


void    print_map()
{
	
	int i;
	int x;
	int y;
	int mem = 1024*4;
	y = 1;
	
	i = 0;
	ft_adaptive();
	while(y < 66)
	{
		x = 2;
		while (i < MEM_SIZE)
		{
			set_color_on_map((int)g_dt.map[0][i], (int)g_dt.map[1][i], (int)g_dt.map[2][i]);
			mvwprintw(g_vh.gen_win, y, x, "%.2X", (int)g_dt.map[0][i]);
			set_color_off_map((int)g_dt.map[0][i], (int)g_dt.map[1][i], (int)g_dt.map[2][i]);
			++i;
			if (i % 62 == 0)
				break ;
			x += g_vh.step;
		}
		++y;
	}
	wrefresh(g_vh.gen_win);
	wrefresh(g_vh.info);
}

void	init_ncurses(void)
{
	initscr();
	start_color();
	keypad(stdscr, true);
	noecho();
	ft_set_pair();
	curs_set(0);
	ft_adaptive();
	g_vh.gen_win = newwin(g_vh.y, g_vh.xg, 0, 0);
	g_vh.info = newwin(g_vh.y - 30, g_vh.x - g_vh.xg, 0, g_vh.xg);
	g_vh.term = newwin(g_vh.y - 10, g_vh.x - g_vh.xg, g_vh.y - 30, g_vh.xg);
	wattron(g_vh.gen_win, COLOR_PAIR(BORDER));
	wborder(g_vh.gen_win, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.gen_win, COLOR_PAIR(BORDER));
	wattron(g_vh.info, COLOR_PAIR(BORDER));
	wborder(g_vh.info, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.info, COLOR_PAIR(BORDER));
	wattron(g_vh.term, COLOR_PAIR(BORDER));
	wborder(g_vh.term, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.term, COLOR_PAIR(BORDER));
}