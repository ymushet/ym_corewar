//
// Created by Maksym Kaliberda on 14.10.17.
//

#ifndef __VISUALIZATION_H
#define __VISUALIZATION_H

# include <unistd.h>
# include <pthread.h>
# include <ncurses.h>
# include <curses.h>

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "ncurses.h"
# include "curses.h"
# include <pthread.h>
# define FIELD_Y

# define P1 1
# define P2 2
# define P3 3
# define P4 4
# define START 5
# define BORDER 6
# define P1CAR 11
# define P2CAR 12
# define P3CAR 13
# define P4CAR 14
# define AVATAR 15
# define AVATARB 16


typedef struct  s_visual
{
	WINDOW  *gen_win;
	WINDOW  *info;
	WINDOW  *term;
	WINDOW  *avatar;
	int     av_pos;
	int     av_pos_y;
	int     av_pos_x;
	int     width_w;
	int     step;
	int     x;
	int     y;
	int     xg;
	int     xin;
	int     yin;
	int     term_i;
	int     pause;
	int     speed;
}               t_vis;

t_vis        g_vh;


void	init_ncurses(void);
void    print_map();

void    ft_set_pair();

void   set_color_on_map(int gen, int pl, int car);
void   set_color_off_map(int gen, int pl, int car);
void   ft_print_info(void);
void   ft_adaptive();
void    gen_key(void);
void   ft_putstr_vis(char *str);
void    ft_pause_first();
#endif
