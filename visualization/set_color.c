//
// Created by Maksym Kaliberda on 16.10.17.
//

# include "visualization.h"

void   ft_adaptive()
{
	getmaxyx(stdscr, g_vh.y, g_vh.x);
	if (g_vh.x > 400)
		g_vh.step = 5;
	if (g_vh.x < 400 && g_vh.x > 300)
		g_vh.step = 4;
	if (g_vh.x < 300 && g_vh.x > 250)
		g_vh.step = 3;
	if (g_vh.x < 250 && g_vh.x > 200)
		g_vh.step = 2;
	else if (g_vh.x < 200)
		g_vh.step = 2;
	g_vh.xg = g_vh.step * 64;
	g_vh.xin = g_vh.x - g_vh.xg;
}

void    ft_set_pair()
{
	init_color(COLOR_RED, 256, 256, 256);
	init_color(COLOR_WHITE, 255, 204, 204);
	init_pair(START, COLOR_RED, COLOR_BLACK);
	init_pair(P1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(P2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(P3, COLOR_CYAN, COLOR_BLACK);
	init_pair(P4, COLOR_GREEN, COLOR_BLACK);
	init_pair(BORDER, COLOR_WHITE, COLOR_WHITE);
	init_pair(P1CAR, COLOR_RED, COLOR_MAGENTA);
	init_pair(P2CAR, COLOR_RED, COLOR_YELLOW);
	init_pair(P3CAR, COLOR_RED, COLOR_CYAN);
	init_pair(P4CAR, COLOR_RED, COLOR_GREEN);
}

void set_color_on_map(int gen, int pl, int car)
{
	if (pl == 48)
		wattron(g_vh.gen_win, COLOR_PAIR(START));
	if(pl != 48 && car == 48)
		wattron(g_vh.gen_win, COLOR_PAIR(pl - 64));
	if(pl != 48 && car != 48)
		wattron(g_vh.gen_win, COLOR_PAIR(pl - 64 + 10));
}

void set_color_off_map(int gen, int pl, int car)
{
	if (pl == 48)
		wattroff(g_vh.gen_win, COLOR_PAIR(START));
	if(pl != 48)
		wattroff(g_vh.gen_win, COLOR_PAIR(pl - 64));
	if(pl != 48 && car != 48)
		wattron(g_vh.gen_win, COLOR_PAIR(pl - 64 + 10));
}