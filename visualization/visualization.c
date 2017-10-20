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
	int mem = 1024 * 4;
	y = 1;
	gen_key();
	i = 0;
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
			g_dt.cycle++;
		}
		++y;
	}
	wrefresh(g_vh.gen_win);
	wrefresh(g_vh.info);
	ft_pause_first();
}


void fgt(char *str)
{
	int i = 0;
	int x = g_vh.av_pos_x / 2 - 24;
	while (i <= 48)
	{
		wattron(g_vh.avatar, COLOR_PAIR(P4));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		wattroff(g_vh.avatar, COLOR_PAIR(P4));
		i++;
		x++;
	}
	usleep(50000);
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void fgp(char *str)
{
	int i = 0;
	int x = g_vh.av_pos_x / 2 - 24;
	while (i <= 48)
	{
		if (str[i] == 32)
			wattron(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattron(g_vh.avatar, COLOR_PAIR(AVATAR));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		if (str[i] == 32)
			wattroff(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattroff(g_vh.avatar, COLOR_PAIR(AVATAR));
		i++;
		x++;
	}
	usleep(50000);
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void init_avatar()
{
	getmaxyx(stdscr, g_vh.av_pos_y, g_vh.av_pos_x);
	g_vh.avatar = newwin(g_vh.av_pos_y, g_vh.av_pos_x, 0, 0);
	g_vh.av_pos = g_vh.av_pos_y / 2 - 7;
	fgp(" ####   ####  ####  ##### #   #   #    #    ####");
	fgp("#    # #    # #   # #     #   #   #    #    #   #");
	fgp("#      #    # #   # #      #  #  #    # #   #   #");
	fgp("#      #    # ####  #####  #  #  #    # #   ####");
	fgp("#      #    # #   # #      # # # #   #   #  #   #");
	fgp("#      #    # #   # #       #   #    #####  #   #");
	fgp("#    # #    # #   # #       #   #   #     # #   #");
	fgp(" ####   ####  #   # #####   #   #   #     # #   #");
	fgt("                                                 ");
	fgt("                    INSTRUCTION                  ");
	fgt("key space..............................play/pause");
	fgt("key + .............................increase speed");
	fgt("key + .............................decrease speed");
	fgt("                                                 ");
	fgt("                                                 ");
	fgt("              ENTER ANY KEY TO START             ");
	fgt("                                                 ");
	getchar();
	endwin();
}

void	init_ncurses(void)
{
	g_vh.pause = 1;
	initscr();
	start_color();
	keypad(stdscr, true);
	noecho();
	ft_set_pair();
	curs_set(0);
	nodelay(stdscr, true);
	ft_adaptive();
	wattron(g_vh.term, COLOR_PAIR(BORDER));
	wattroff(g_vh.term, COLOR_PAIR(BORDER));
	init_avatar();
	keypad(stdscr, true);
	g_vh.gen_win = newwin(g_vh.y, g_vh.xg, 0, 0);
	g_vh.info = newwin(g_vh.y - g_vh.yin, g_vh.x - g_vh.xg, 0, g_vh.xg);
	g_vh.term = newwin(g_vh.yin, g_vh.x - g_vh.xg, g_vh.y - g_vh.yin , g_vh.xg);
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